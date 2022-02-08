#!/usr/bin/env python
#### Solves large and small problem instances of the always-turn-left
#### problem: http://code.google.com/codejam/contest/dashboard?c=32003#s=p1

import numpy as np

cell_descs = {} # uints from 1 to 15

moves = ['W', 'R', 'L']

non_dir_moves = 'FRBL'
non_dir_moves_lookup = \
    dict(map(lambda x, y: (x, 2**y),
             non_dir_moves, xrange(len(non_dir_moves))))

def get_non_dir_cell_desc(prev_move, move):
    allowed_moves = None
    disallowed_moves = None
    
    if move == 'L':
        allowed_moves = [3]
        disallowed_moves = []
    elif move == 'W':
        allowed_moves = [0]
        
        # Was 'W' chosen because 'L' is not allowed or because 'L' was
        # previously chosen?
        if prev_move == 'L':
            disallowed_moves = []
        else:
            disallowed_moves = [3]
    elif move == 'R':
        allowed_moves = []
        disallowed_moves = [3, 0]

    return allowed_moves, disallowed_moves

dirs = 'NESW'
dirs_idx_lookup = \
    dict(map(lambda x, y: (x, y), dirs, xrange(len(dirs))))

def rotate_non_dir_cell_desc(non_dir_desc, heading):
    return \
    map(lambda non_dir_moves:
        map(lambda x: (x + heading) % 4, non_dir_moves),
        non_dir_desc)

def get_cell_desc(heading, prev_move, move):
    non_dir_desc = get_non_dir_cell_desc(prev_move, move)
    dir_desc = rotate_non_dir_cell_desc(non_dir_desc, heading)
    return dir_desc

def get_next_state(curr_coords, curr_heading, move):
    next_coords = curr_coords
    next_heading = curr_heading

    if move == 'L':
        next_heading = (next_heading + 3) % 4
        return next_coords, next_heading
    
    if move == 'R':
        next_heading = (next_heading + 1) % 4
        return next_coords, next_heading

    # coordinates grow towards SW corner
    next_coords = curr_coords
    if curr_heading == 0:
        next_coords[1] -= 1
    elif curr_heading == 2:
        next_coords[1] += 1
    elif curr_heading == 3:
        next_coords[0] += 1
    elif curr_heading == 1:
        next_coords[0] -= 1

    return next_coords, next_heading

def get_path_info(path, start_coords, start_heading):
    descs = []
    coords = []

    curr_coords = list(start_coords)
    curr_heading = start_heading

    prev_move = 'W'
    for move in path:
        descs.append(get_cell_desc(curr_heading, prev_move, move))
        coords.append(list(curr_coords))
        curr_coords, curr_heading = \
            get_next_state(curr_coords, curr_heading, move)

        prev_move = move

    # Correct the last step - the 'W' occurs to exit the maze, not
    # because 'L' is not allowed.
    descs[-1][1] = []

    return zip(coords, descs), curr_heading

def add_path_infos_to_coord_infos(coord_infos, path_info):
    for coords, desc in path_info:
        coords = tuple(coords)
        
        coord_info = coord_infos.get(coords, (set([]), set([])))
        coord_info = (coord_info[0] | set(desc[0]),
                      coord_info[1] | set(desc[1]))
        coord_infos[coords] = coord_info

def get_maze_coord_infos(entrance_to_exit, exit_to_entrance):
    start_coords = [0, 0] # start one block down from start
    start_heading = 2 # start facing S
    
    fwd_path_info, end_heading = \
        get_path_info(entrance_to_exit[1:],
                      start_coords, start_heading)

    # Set up the reverse direction
    end_coords = list(fwd_path_info[-1][0])
    rev_end_heading = (end_heading + 2) % 4
    rev_path_info, _ = \
        get_path_info(exit_to_entrance[1:],
                      end_coords, rev_end_heading)

    # Combine path info
    coord_infos = {}
    add_path_infos_to_coord_infos(coord_infos, fwd_path_info)
    add_path_infos_to_coord_infos(coord_infos, rev_path_info)

    return coord_infos

NESW_to_NSWE_lookup = {
    0 : 0,
    1 : 3,
    2 : 1,
    3 : 2
}
def convert_NESW_to_NSWE(dir):
    return NESW_to_NSWE_lookup[dir]

def generate_maze_description(coord_infos):
    max_coords = max(coord_infos.iterkeys())
    min_coords = min(coord_infos.iterkeys())

    maze_desc = ""

    for row in xrange(min_coords[1], max_coords[1]+1):
        for col in xrange(max_coords[0], min_coords[0]-1, -1):
            allowed_moves = coord_infos[(col, row)][0]
            allowed_moves = map(convert_NESW_to_NSWE, allowed_moves)

            room_desc = 0

            for move in allowed_moves:
                room_desc += 2**move

            maze_desc += hex(room_desc)[-1]

        maze_desc += '\n'

    return maze_desc[:-1]

def describe_maze(entrance_to_exit, exit_to_entrance):
    return \
    generate_maze_description(
        get_maze_coord_infos(entrance_to_exit, exit_to_entrance))

maze_desc = describe_maze('WRWWLWWLWWLWLWRRWRWWWRWWRWLW', 'WWRRWLWLWWLWWLWWRWWRWWLW')

import sys
ntestcases = int(sys.stdin.readline())

for x in xrange(ntestcases):
   entrance_to_exit, exit_to_entrance = sys.stdin.readline().split()
   desc = describe_maze(entrance_to_exit, exit_to_entrance)
    
   print "Case #%d:" % (x+1)
   print desc
