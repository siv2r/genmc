atomic_int x;
atomic_int y;

void *thread_one(void *arg)
{
	atomic_store_explicit(&x, 1, memory_order_release);
	atomic_load_explicit(&y, memory_order_acquire);
	atomic_load_explicit(&x, memory_order_acquire);
	return NULL;
}

void *thread_two(void *arg)
{
	atomic_store_explicit(&x, 2, memory_order_release);
	atomic_load_explicit(&x, memory_order_acquire);
	return NULL;
}

void *thread_three(void *arg)
{
	atomic_store_explicit(&y, 3, memory_order_release);
	return NULL;
}
