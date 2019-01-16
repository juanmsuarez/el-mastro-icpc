with open("holes.in","r") as filein, open("holes.out","w") as fileout 
    h = int(filein.read())
    res=''
    if h==0:
        res='1'
    elif h==1:
        res='0'
    else:
        if h%2:
            res='4'
        res+=(h//2)*'8'
    fileout.write(res)
