from subprocess import Popen, PIPE
import optparse
import sys

class ImageFile():
    def __init__(self, num=None, size=None, dest=None):
        self.num = num
        self.size = size
        self.dest = dest

    def CreateImage(self):
        value = "%sMB " % str(self.size/1024)
        for i in range(self.num):
            try:
                cmd = "dd if=/dev/zero of=%s/file.%s bs=1024 count=%s" % (self.dest,i,self.size)
                print cmd
                Popen(cmd,shell=True, stdout=PIPE)
            except Exception, err:
                sys.stderr.write(err)

    def controller(self):
        p = optparse.OptionParser(description="Launches Many dd", prog="Many dd", version="0.1", usage="%prog [options] dest")
        p.add_option('-d', '--destination', help='Destination directory', type=str)
        p.add_option('-n', '--number', help='set many dd', type=int)
        p.add_option('-s', '--size', help='size of image in bytes', type=int)
        p.set_defaults(number=10, size=10240, destination="/tmp")
        options, arguments = p.parse_args()
        if len(arguments) == 1:
            self.dest = options.destination
            self.size = options.size
            self.num = options.number
            self.createImage()
def main():
    start = ImageFile()
    start.controller()

if __name__ == '__main__':
    main()