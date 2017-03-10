# IPO - Is Port Open
Quickly scan a hostname for open TCP ports, from a command line interface.

## Building and installing on linux
Clone repo, and simply run ./install-linux.sh.

## Syntax

```bash
ipo [hostname] [port1] [port2] ...
```

### Examples

__Scanning localhost for web servers__

```bash
$ ipo localhost 80 443 8080
Scanning host localhost
Port 80 is open!
Port 443 is open!
Port 8080 closed.
```

__Scanning another machine for SMTP__

```bash
$ ipo mail.someserver.com 25
Scanning host mail.someserver.com
Port 25 is open!
```
