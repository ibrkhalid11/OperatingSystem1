def generate_isrs(max_num):
    for i in range(max_num +1):
        print(f"extern void irq{i}(void);")

if __name__ == "__main__":
    generate_isrs(15);
