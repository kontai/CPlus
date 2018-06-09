class VAHP {
public:
	VAHP(const int &p, int va) :val_ptr(new int(p)), val(va) {
	}

	VAHP(const VAHP& obj) :val_ptr(new int(*obj.val_ptr)), val(obj.val) {
	}
	VAHP& operator=(const VAHP& eobj) {
		//val_ptr = new int;
		*val_ptr = *eobj.val_ptr;
		val = eobj.val;
	}
	~VAHP() {
		delete val_ptr;
	};

	int *get_ptr() {
		return val_ptr;
	}

	int get_int() {
		return val;
	}

	void set_ptr(int *v1) {
		val_ptr = v1;
	}

	void set_int(int i) {
		val = i;
	}

	int get_ptr_val()const {
		return *val_ptr;
	}

	void set_ptr_val(int val) {
		*val_ptr = val;
	}

private:
	int *val_ptr;
	int val;
};
