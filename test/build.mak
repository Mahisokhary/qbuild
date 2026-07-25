TEST_OBJS := $(patsubst %,$(BUILD_DIR)/obj/%.o,$(call RESOLVE_SOURCES,test,.c))

$(BUILD_DIR)/test: $(TEST_OBJS) | $(BUILD_DIR)/libqbuild.so
	$(info > Linking $@)
	gcc $(GCC_FLAGS) $(TEST_OBJS) -o $@ -lqbuild

