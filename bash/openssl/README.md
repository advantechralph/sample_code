### Openssl Command Line Notes
** AES Encryption & Deecryption **
```
# Encryption
echo "message" | openssl enc -aes-256-cbc -a -pass pass:$password
# Decryption
echo "encmessage" | openssl enc -aes-256-cbc -a -d -pass pass:$password
```
** Create Self-signed Certification **

```
```

