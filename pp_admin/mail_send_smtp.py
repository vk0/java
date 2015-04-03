#!/usr/bin/env python2

import smtplib
mail_server = 'localhost'
mail_server_port = 25
from_addr = 'me@me.ru'
to_addr = "me@me.ru"

from_header = 'From: %s\r\n' % from_addr
to_header = 'To: %s\r\n\r\n' % to_addr
subject_header = 'Subject: HELLO'

body = 'HELLO'

email_message = '%s\n%s\n%s\n\n%s' % (from_header, to_header, subject_header, body)

s = smtplib.SMTP(mail_server, mail_server_port)
s.sendmail(from_addr, to_addr, email_message)
s.quit()
