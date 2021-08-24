#!/bin/bash
make clean 
make
sudo git add .
sudo git commit
sudo git push --force -u origin HEAD:master
sudo git push -u origingl HEAD:master
echo done!
