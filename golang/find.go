package main

import (
	"flag"
	"log"
	"os"
	"syscall"
	"unsafe"
	"path/filepath"
	"bufio"
)

var (
	bufout = bufio.NewWriter(os.Stdout)
)

func clen(n []byte) int {
	for i := 0; i < len(n); i++ {
		if n[i] == 0 {
			return i
		}
	}
	return len(n)
}

func readdir(dir string, file string, dirfd int, pathbuf []byte) {
	origbuf := make([]byte, 4096)

	dh, err := syscall.Openat(dirfd, file, syscall.O_RDONLY, 0777)
	if err != nil {
		log.Fatalf("Could not open %s/%s: %s", dir, file, err.Error())
	}

	origpathbuf := pathbuf[0:0]

	for {
		n, errno := syscall.ReadDirent(dh, origbuf)
		if errno != nil {
			log.Fatalf("Could not read dirent: %s", err.Error())
		}
		if n <= 0 {
			break // EOF
		}

		buf := origbuf[0:n]
		for len(buf) > 0 {
			dirent := (*syscall.Dirent)(unsafe.Pointer(&buf[0]))
			buf = buf[dirent.Reclen:]
			if dirent.Ino == 0 { // File absent in directory.
				continue
			}
			bytes := (*[10000]byte)(unsafe.Pointer(&dirent.Name[0]))
			name := bytes[0:clen(bytes[:])]
			if len(name) == 1 && name[0] == '.' || len(name) == 2 && name[0] == '.' && name[1] == '.' { // Useless names
				continue
			}

			pathbuf = append(pathbuf, dir...)
			pathbuf = append(pathbuf, '/')
			pathbuf = append(pathbuf, file...)
			dirlen := len(pathbuf)

			pathbuf = append(pathbuf, '/')
			pathbuf = append(pathbuf, name...)
			pathbuf = append(pathbuf, '\n')

			bufout.Write(pathbuf)

			if dirent.Type == syscall.DT_UNKNOWN {
				st, err := os.Stat(dir + "/" + file + "/" + string(name))
				if err != nil {
					log.Fatalf("Could not stat: %s", err.Error())
				}
				if st.IsDir() {
					dirent.Type = syscall.DT_DIR
				}
			}

			if dirent.Type == syscall.DT_DIR {
				readdir(string(pathbuf[0:dirlen]), string(name), dh, origpathbuf)
			}

			pathbuf = origpathbuf[0:0]
		}

		buf = origbuf[0:0]
	}

	syscall.Close(dh)
}

func main() {
	flag.Parse()
	if flag.NArg() != 1 {
		log.Fatalf("Usage: %s <dir>", os.Args[0])
	}

	dir := flag.Arg(0)
	parentDir := filepath.Dir(dir)

	dh, err := os.Open(parentDir)
	if err != nil {
		log.Fatalf("Could not open dir: %s", err.Error())
	}

	pathbuf := make([]byte, 16 * 1024)
	readdir(parentDir, filepath.Base(dir), int(dh.Fd()), pathbuf)
	bufout.Flush()
}
