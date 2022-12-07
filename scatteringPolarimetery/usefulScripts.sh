
# When you want to create a new Geant4 project from an existing project
# the following bash script snippets will help to rename the files as 
# well as rename the classes etc.

# Rename files in batch: For all include & src files, names having string 'B1' is replaced with 
# mydet
for f in include/*.hh; do a="$(echo $f | sed s/B1/mydet/)"; mv "$f" "$a"; done
for f in src/*.cc; do a="$(echo $f | sed s/B1/mydet/)"; mv "$f" "$a"; done

#Replace string in all files in all subfolders recursively 
#Here the string B1 is replaced by mydet 
find . -type f -exec sed -i 's/B1/mydet/g' {} +

