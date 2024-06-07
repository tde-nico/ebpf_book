BPF_PROG_ARRAY(syscall, 300);

int hello(struct bpf_raw_tracepoint_args *ctx) {
	int opcode = ctx->args[1];
	syscall.call(ctx, opcode);
	bpf_trace_printk("Another syscall: %d", opcode);
	return 0;
}

int hello_exec(void *ctx) {
	bpf_trace_printk("Executing a program");
	return 0;
}

int hello_timer(struct bpf_raw_tracepoint_args *ctx) {
	int opcode = ctx->args[1];
	switch (opcode) {
		case 222:
			bpf_trace_printk("Creating a timer");
			break;
		case 226:
			bpf_trace_printk("Deleting a timer");
			break;
		default:
			bpf_trace_printk("Some other timer operation");
			break;
	}
	return (0);
}

int ignore_opcode(void *ctx) {
	return (0);
}
