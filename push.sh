#!/bin/bash
git init
git add .gitignore
git commit -m "First Commit"
git pull origin master
git remote add origin https://github.com/Nightwing52/CAT
git -v
git push origin master