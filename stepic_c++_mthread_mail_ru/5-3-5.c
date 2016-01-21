// Соберите функцию блокировки через существование файла.

bool lock(std::string path) {
int f = open(path.c_str(), O_RDWR|O_CREAT|O_EXCL,0666);
if(f>0){
    close(f);
    return true;
} else return false;
}
