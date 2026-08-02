CLI_OBJS := $(patsubst %,$(BUILD_DIR)/obj/%.o,$(call RESOLVE_SOURCES,cli,.c))

$(BUILD_DIR)/qbuild: $(CLI_OBJS) | $(BUILD_DIR)/libqbuild.so
	$(info > Linking $@)
	gcc $(GCC_FLAGS) -pie $(CLI_OBJS) -o $@ -lqbuild
BUILD_TARGETS += $(BUILD_DIR)/qbuild

