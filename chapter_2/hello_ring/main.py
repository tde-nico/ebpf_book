from bcc import BPF

b = BPF('source.c')
syscall = b.get_syscall_fnname("execve")
b.attach_kprobe(event=syscall, fn_name="hello")

def print_event(cpu, data, size):
	data = b['output'].event(data)
	print(f"{data.pid} {data.uid} {data.command.decode()} {data.message.decode()}")

b['output'].open_perf_buffer(print_event)
while True:
	b.perf_buffer_poll()
