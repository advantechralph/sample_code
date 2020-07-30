
1. Change the identity files location. 
   Edit **~/.ssh/config**
   ex: 
   ```
   Host 192.168.2.14
      HostName 192.168.2.14
      IdentityFile ~/.ssh/status/ssh/id_rsa
      User git
   ```
2. How to disable strict host key checking in ssh? 
   Edit **~/.ssh/config**
   ```
   Host *
       StrictHostKeyChecking no
   ```
