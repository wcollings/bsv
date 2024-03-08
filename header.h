struct header {
	union {
		int32_t bits;
		struct {
			int num_cols:8;
			int has_names:1;
			int is_64:1;
			int pad:2;
			int dtype:4;
		};
	} meta;
	char** names;
};

const struct * header parse_header(FILE * fptr);
