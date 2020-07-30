# vim: softtabstop=2 ts=2 sw=2 et
#!/bin/bash
dir=mirror
# src url example: gitolite@git.lab317.org:dinos80152/Authentication
mirrorSrcUrl=git@github.com:buildroot/buildroot.git
# dst url example: git@gitlab.lab317.org:dinos80152/Authentication.git
mirrorDstUrl=git@bitbucket.org:bearout/buildroot.x86.git

# clone the mirror you want to move
#git clone --mirror $mirrorSrcUrl $dir

# set the new remote location
#cd $dir
git remote set-url --push origin $mirrorDstUrl

# clean local origin 
git fetch -p origin

# push mirror to new location
git push --mirror
