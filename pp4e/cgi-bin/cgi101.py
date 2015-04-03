#!/usr/bin/env python
import cgi
form = cgi.FieldStorage()
print('Content-type: text/html\n')
print('<title>Reply Page</title>')
if not 'user' in form:
    print('<h1>Who are you?</h1>')
else:
    value = form.getlist("user")
    print('<h1>Helo <i>%s</i>!</h1>' % value)
