#!/usr/bin/python
import sys
fp = file(sys.argv[1])
for case in range(int(fp.next())):
    #INITIALIZE#
    (num,pack) = fp.next().split()
    ingredients=fp.next().split()
    servings=[]
    print int(num),pack,ingredients
    for p in range(int(num)):
        serves=[]
        packages=fp.next().split()
        for package in packages:
            serve = int(round(float(package)/int(ingredients[p])))
            print package,ingredients[p],serve
            if serve*int(ingredients[p])*0.9 <= int(package) <= serve*int(ingredients[p])*1.1:
                serves.append(serve)
            else:
                serves.append(0)
        servings.append(sorted(serves)[::-1])
    print servings
    #INITIALIZE#
    #----------#
    #MAIN  CODE#
    res=0
    c=0
    for serve in range(0,int(pack)):
        flag=True
        amount=servings[0][serve-c]
        for i in range(0,int(num)):
            if not amount in servings[i]:
                flag=False
        if flag:
            c+=1
            for i in range(0,int(num)):
                del servings[i][servings[i].index(amount)]
            res+=1
    #MAIN   CODE#
    #############
    #O U T P U T#
    print "Case #%d: %s" % (case+1, res)
fp.close()
