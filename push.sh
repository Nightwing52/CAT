#!/bin/bash
git init
git add .
git commit -m "First Push"
git pull origin master
git remote add origin https://github.com/Nightwing52/CAT
git -v
git push origin master