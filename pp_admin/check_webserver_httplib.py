#!/usr/bin/env python

import httplib
import sys

def check_webserver(address, port, resource):
    """

    :param address:
    :param port:
    :param resource:
    :return:
    """
    if not resource.startswith('/'):
        resource = '/' + resource

    try:
        conn = httplib.HTTPConnection(address,port)
        print('HTTP connection created successfully')
        req = conn.request('GET', resource)
        print('request for %s succesful' % resource)
        response = conn.getresponse()
        print('response status: %s' % response.status)
    #except conn.error, e:
    except:
        print('HTTP connection failed: %s')
        return False
    finally:
        conn.close()
        print('Closing the connection')
    if response.status in [200,301]:
        return True
    else:
        return False

if __name__ == '__main__':
    from optparse import  OptionParser
    parser = OptionParser()
    parser.add_option('-a', '--address', dest='address', default='localhost', help='ADDRESS for webserver', metavar='ADDRESS')
    parser.add_option('-p', '--port', dest='port', type='int', default=80, help='PORT for webserver', metavar='PORT')
    parser.add_option('-r', '--resource', dest='resource', default='index.html', help='RESOURCE to check', metavar='RESOURCE')
    (options,args) = parser.parse_args()
    print('options: %s, args: %s' % (options,args))
    check = check_webserver(options.address, options.port, options.resource)
    print('check_webserver returned %s' % check)
    sys.exit(not check)
