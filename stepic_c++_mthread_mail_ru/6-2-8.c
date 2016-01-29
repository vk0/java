// Создайте очередь сообщения SysV с ключем:

// key_t key = ftok("/tmp/msg.temp", 0);

// Тестовая среда пошлет в нее сообщение.

// struct message {
//     long mtype;
//     char mtext[80];
// }

// Получите его и сохраните в /home/box/message.txt