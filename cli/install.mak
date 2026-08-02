$(INSTALL_DIR)/usr/bin/qbuild: $(BUILD_DIR)/qbuild
	$(info > Installing $@)
	install -Dm755 $< $@

INSTALL_TARGETS += $(INSTALL_DIR)/usr/bin/qbuild

