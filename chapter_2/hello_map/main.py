from bcc import BPF
from time import sleep

b = BPF('source.c')
syscall = b.get_syscall_fnname("execve")
b.attach_kprobe(event=syscall, fn_name="hello")

while True:
	sleep(2)
	s = ""
	for k, v in b['counter_table'].items():
		s += f'ID {k.value}: {v.value}\t'
	print(s)

