QBUILD_INSTALL_HEADERS = $(call INSTALL_HEADER_RESOLVER,qbuild)

$(INSTALL_DIR)/usr/lib/libqbuild.so: $(BUILD_DIR)/libqbuild.so
	$(info > Installing $@)
	install -Dm755 $< $@

INSTALL_TARGETS += \
		$(INSTALL_DIR)/usr/lib/libqbuild.so \
		$(call INSTALL_HEADER_TO_TARGET,qbuild,$(QBUILD_INSTALL_HEADERS))

