#!/bin/bash
python -B main.py
python - << EOF
print "heredoc sample code!!"
EOF
