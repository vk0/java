import subprocess

machines = ['me.example.ru']
cmd = 'uname'
for machine in machines:
    subprocess.call('ssh root@%s %s' % (machine, cmd), shell=True)