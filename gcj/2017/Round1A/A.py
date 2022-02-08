#!/usr/bin/python
import sys
fp = file(sys.argv[1])
for case in range(int(fp.next())):
    (row,column) = fp.next().split()
    Matrix=[]
    Row=[]
    Blank_rows=[]
    for i in range(int(row)):
        r=fp.next()
        Matrix.append(r[:int(column)])
    #MAIN
    flagg=0
    for i in range(int(row)):
        r=Matrix[i]
        if r=="?"*int(column) and flagg==0:
            continue
        elif r=="?"*int(column):
            Matrix[i]=flagg
        else:
            flag=0
            for j in range(int(column)):
                if r[j]=="?" and flag == 0:
                    continue
                elif r[j]=="?":
                    r=r[:j]+flag+r[j+1:]
                elif flag==0:
                    r=r[j]*j+r[j:]
                flag=r[j]
            Matrix[i]=r
            if flagg==0:
                Matrix=[Matrix[i]]*i+Matrix[i:]
            flagg=Matrix[i]
                
    """
        Row=[]
        flag=-1
        for j in range(int(column)):
            if r[j] != "?" and flag ==-1:
                flag=[j,r[j]]
            Row.append(r[j])
        if flag != -1:
            Matrix.append(Row+[i]+flag)
        if flag == -1:
            Blank_rows.append(i)
            
    print "Blank:",Blank_rows,"\nMatrix:",Matrix
    #MAIN
    continue
    r=0
    flag=0
    for i in range(len(Matrix)):
        flag_column=0
        Row=Matrix[i]
        for j in range(int(column)):
            if j < Row[column+1]:
                
            pass
    """
    print "Case #%d:" % (case+1)
    for i in Matrix:
        print i
fp.close()
