#!/bin/bash
git init
git add .gitignore
git commit -m "Renamed windows.h and Script Loading"
git pull origin master
git remote add origin https://github.com/Nightwing52/CAT
git -v
git push origin master