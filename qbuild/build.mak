QBUILD_OBJS := $(patsubst %,$(BUILD_DIR)/obj/%.o,$(call RESOLVE_SOURCES,qbuild,.c))

$(BUILD_DIR)/libqbuild.so: $(QBUILD_OBJS)
	$(info > Linking $@)
	gcc $(GCC_FLAGS) --shared $(QBUILD_OBJS) -o $@ -lqson
BUILD_TARGETS += $(BUILD_DIR)/libqbuild.so

