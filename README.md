# 🧵 MiniSock

**MiniSock** is a minimalist client-server application written in C using raw sockets. It demonstrates the basics of TCP communication, where a server waits for client messages and prints them upon receipt.

---

## 📚 Overview

- 🖥 Server listens on **localhost:6969**
- 📡 Client sends one message and exits
- 🔒 Single client at a time (no concurrency)

---

## 🛠 How It Works

### 🖥 Server

- Creates a TCP socket
- Binds to port `6969` on all interfaces
- Listens and accepts incoming connections in a loop
- Reads the client's message and prints it
- Closes connection after each message

### 📡 Client

- Connects to `127.0.0.1:6969`
- Sends a message from the command line
- Closes connection immediately after

---

## 🚀 Usage

### ✅ Compile

```bash
make
```
### ▶️ Run the Server

```bash
./server
```

### 📤 Send a Message with the Client

```bash
./client "Hello, MiniSock!"
```
