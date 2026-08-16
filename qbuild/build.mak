ifdef RELEASE
GCC_FLAGS += -DQBUILD_CONTEXT_CONFIG_PATH='"/usr/lib/qbuild/:/etc/qbuild/"'
else
GCC_FLAGS += -DQBUILD_CONTEXT_CONFIG_PATH='"./qbuild/config/"'
endif

QBUILD_OBJS := $(patsubst %,$(BUILD_DIR)/obj/%.o,$(call RESOLVE_SOURCES,qbuild,.c))

$(BUILD_DIR)/libqbuild.so: $(QBUILD_OBJS)
	$(info > Linking $@)
	gcc $(GCC_FLAGS) --shared $(QBUILD_OBJS) -o $@ -lqson
BUILD_TARGETS += $(BUILD_DIR)/libqbuild.so

