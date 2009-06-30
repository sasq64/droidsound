

DROID=/home/sasq/mydroid/

package:
	cp bin/droidsound.apk bin/droidsound.orig.apk
	mv bin/droidsound.apk package.apk
	rm -rf lib
	mkdir -p lib/armeabi
	cp *.so lib/armeabi
	zip -r package.apk lib
	#zip -qj package.apk classes.dex
	mv package.apk package.apk.unsigned
	java -jar $(DROID)/out/host/linux-x86/framework/signapk.jar $(DROID)/build/target/product/security/testkey.x509.pem $(DROID)/build/target/product/security/testkey.pk8 package.apk.unsigned package.apk.signed
	mv package.apk.signed package.apk
	mv package.apk package.apk.unaligned
	$(DROID)/out/host/linux-x86/bin/zipalign -f 4 package.apk.unaligned package.apk.aligned
	mv package.apk.aligned package.apk
	$(DROID)/out/host/linux-x86/bin/acp -fpt package.apk bin/droidsound.apk
	rm package.apk*

	
	
	# make -C ../ModPlugin -f android.mk
	# cp ../ModPlugin/*.so .
	# make -C ../TinySidPlugin -f android.mk
	# cp ../TinySidPlugin/*.so .
	# make -C ../GMEPlugin -f android.mk
	# cp ../GMEPlugin/*.so .
	