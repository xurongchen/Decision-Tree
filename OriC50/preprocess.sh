cd $1

src="global.c \
c50.c \
construct.c \
formtree.c \
info.c \
discr.c \
contin.c \
subset.c \
prune.c \
p-thresh.c \
trees.c \
siftrules.c \
ruletree.c \
rules.c \
getdata.c \
implicitatt.c \
mcost.c \
confmat.c \
sort.c \
update.c \
attwinnow.c \
classify.c \
formrules.c \
getnames.c \
modelfiles.c \
utility.c \
xval.c \
debug.c"

cat defns.i ${src} | egrep -v 'defns.i|extern.i' > $1/c50gt.c
