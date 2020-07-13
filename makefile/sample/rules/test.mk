
.PHONY: test

test: prepare 
	@echo "$(call logncmd,gcc -o test test.c,.test)"
