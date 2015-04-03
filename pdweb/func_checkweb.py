import httplib
def c_w_s(host, port, path):
    h = httplib.HTTPConnection(host, port)
    h.request('GET', path)
    resp = h.getresponse()
    print('HTTP Response:')
    print('status =', resp.status)
    print('reason =', resp.reason)
    print('HTTP Headers:')
    # for hdr in resp.getheader():
    #     print ('%s: %s' % hdr)