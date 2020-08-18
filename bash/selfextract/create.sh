#!/bin/bash
rm -rf project self-extracting Setup
cat << 'EOF' > self-extracting
#!/bin/sh -e
sed -e '1,/^exit$/d' "$0" | tar xzf - && ./Setup
exit
EOF
mkdir -p project
echo "#!/bin/sh" > project/Setup
echo "echo This is the setup script!" >> project/Setup
chmod +x project/Setup
#tar czf - project >> self-extracting
tar -C project -czf - .  >> self-extracting
rm -rf project
chmod +x self-extracting
