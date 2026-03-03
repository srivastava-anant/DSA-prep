#!/bin/bash

# Navigate to your project folder (optional if running from the root)
# git add all changes
git add .

# Prompt for a commit message
echo "Enter commit message:"
read message

# Commit with the message
git commit -m "$message"

# Push to the main branch (change 'main' to 'master' if needed)
git push origin main

echo "Done! Code is now on GitHub."
