#!/usr/bin/env python2

import poplib

username = 'me@example.ru'
password = ''

mail_server = 'example.ru'

p = poplib.POP3(mail_server)
p.user(username)
p.pass_(password)

for msg_id in p.list()[1]:
    print msg_id
    outf = open('%s.eml' % msg_id, 'w')
    outf.write('\n'.join(p.retr(msg_id[1])))
    outf.close()
p.quit()
