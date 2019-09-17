set -x

/bin/bash -c "(mkdir -p out/target/product/morgan3g/system/usp/ ) && (rm -f out/target/product/morgan3g/system/usp/usp-apks-path-OP120.txt )"

/bin/bash -c "(mkdir -p out/target/product/morgan3g/system/usp/ ) && (rm -f out/target/product/morgan3g/system/usp/usp-apks-path-OP06.txt )"

/bin/bash -c "(mkdir -p out/target/product/morgan3g/system/usp/ ) && (rm -f out/target/product/morgan3g/system/usp/usp-apks-path-OP11.txt )"

/bin/bash -c "(mkdir -p out/target/product/morgan3g/system/usp/ ) && (rm -f out/target/product/morgan3g/system/usp/usp-apks-path-OP16.txt )"

/bin/bash -c "(mkdir -p out/target/product/morgan3g/system/usp/ ) && (rm -f out/target/product/morgan3g/system/usp/usp-apks-path-OP15.txt )"

/bin/bash -c "(mkdir -p out/target/product/morgan3g/system/usp/ ) && (rm -f out/target/product/morgan3g/system/usp/usp-apks-path-OP03.txt )"

/bin/bash -c "(mkdir -p out/target/product/morgan3g/system/usp/ ) && (rm -f out/target/product/morgan3g/system/usp/usp-apks-path-OP05.txt )"

/bin/bash -c "(mkdir -p out/target/product/morgan3g/system/usp/ ) && (rm -f out/target/product/morgan3g/system/usp/usp-packages-all.txt )"

/bin/bash -c "(mkdir -p out/target/product/morgan3g/system/usp/ ) && (rm -f out/target/product/morgan3g/system/usp/usp-apks-path-OP130.txt )"

/bin/bash -c "(mkdir -p out/target/product/morgan3g/system/usp/ ) && (rm -f out/target/product/morgan3g/system/usp/usp-apks-path-OP112.txt )"

/bin/bash -c "(mkdir -p out/target/product/morgan3g/system/usp/ ) && (rm -f out/target/product/morgan3g/system/usp/usp-apks-path-OP201.txt )"

/bin/bash -c "(mkdir -p out/target/common/obj/JAVA_LIBRARIES/svclib_intermediates/ && rm -f out/target/common/obj/JAVA_LIBRARIES/svclib_intermediates/link_type ) && (echo \"java:platform\" >out/target/common/obj/JAVA_LIBRARIES/svclib_intermediates/link_type )"

# rm -f out/target/common/obj/JAVA_LIBRARIES/svclib_intermediates/java-source-list ; rm -f out/target/common/obj/JAVA_LIBRARIES/svclib_intermediates/java-source-list.tmp 
find frameworks/base/cmds/svc/src/com/android/commands/svc/* -type f -name '*.java'|sort -u >  out/target/common/obj/JAVA_LIBRARIES/svclib_intermediates/java-source-list 
# /bin/bash -c " (> out/target/common/obj/JAVA_LIBRARIES/svclib_intermediates/java-source-list.tmp ) && (echo -n 'frameworks/base/cmds/svc/src/com/android/commands/svc/BluetoothCommand.java frameworks/base/cmds/svc/src/com/android/commands/svc/DataCommand.java frameworks/base/cmds/svc/src/com/android/commands/svc/NfcCommand.java frameworks/base/cmds/svc/src/com/android/commands/svc/PowerCommand.java frameworks/base/cmds/svc/src/com/android/commands/svc/Svc.java frameworks/base/cmds/svc/src/com/android/commands/svc/UsbCommand.java frameworks/base/cmds/svc/src/com/android/commands/svc/WifiCommand.java ' >> out/target/common/obj/JAVA_LIBRARIES/svclib_intermediates/java-source-list.tmp ) && (if [ -d \"out/target/common/obj/JAVA_LIBRARIES/svclib_intermediates/src\" ]; then find out/target/common/obj/JAVA_LIBRARIES/svclib_intermediates/src -name '*.java' -and -not -name '.*' >> out/target/common/obj/JAVA_LIBRARIES/svclib_intermediates/java-source-list.tmp; fi ) && (tr ' ' '\\n' < out/target/common/obj/JAVA_LIBRARIES/svclib_intermediates/java-source-list.tmp | build/make/tools/normalize_path.py | sort -u > out/target/common/obj/JAVA_LIBRARIES/svclib_intermediates/java-source-list )"

/bin/bash -c "cat frameworks/base/cmds/svc/NOTICE > out/target/product/morgan3g/obj/NOTICE_FILES/src/system/framework/svc.jar.txt"

/bin/bash -c "cat frameworks/base/cmds/svc/NOTICE > out/target/product/morgan3g/obj/NOTICE_FILES/src/system/bin/svc.txt"

/bin/bash -c "(rm -f out/target/product/morgan3g/obj/EXECUTABLES/svc_intermediates/svc ) && (cp \"frameworks/base/cmds/svc/svc\" \"out/target/product/morgan3g/obj/EXECUTABLES/svc_intermediates/svc\" ) && (chmod +x out/target/product/morgan3g/obj/EXECUTABLES/svc_intermediates/svc )"

/bin/bash -c "(rm -f out/target/common/obj/JAVA_LIBRARIES/svclib_intermediates/classes-full-debug.jar ) && (rm -rf out/target/common/obj/JAVA_LIBRARIES/svclib_intermediates/classes out/target/common/obj/JAVA_LIBRARIES/svclib_intermediates/anno ) && (mkdir -p out/target/common/obj/JAVA_LIBRARIES/svclib_intermediates/ ) && (mkdir -p out/target/common/obj/JAVA_LIBRARIES/svclib_intermediates/classes out/target/common/obj/JAVA_LIBRARIES/svclib_intermediates/anno ) && (if [ -s out/target/common/obj/JAVA_LIBRARIES/svclib_intermediates/java-source-list ] ; then out/soong/host/linux-x86/bin/soong_javac_wrapper  prebuilts/jdk/jdk9/linux-x86/bin/javac -Xmaxerrs 9999999 -encoding UTF-8 -sourcepath \"\" -g -XDskipDuplicateBridges=true -XDstringConcat=inline -encoding UTF-8   -bootclasspath out/target/common/obj/JAVA_LIBRARIES/core-oj_intermediates/classes-header.jar:out/target/common/obj/JAVA_LIBRARIES/core-libart_intermediates/classes-header.jar:out/target/common/obj/JAVA_LIBRARIES/ext_intermediates/classes-header.jar:out/target/common/obj/JAVA_LIBRARIES/framework_intermediates/classes-header.jar:out/target/common/obj/JAVA_LIBRARIES/okhttp_intermediates/classes-header.jar:out/target/common/obj/JAVA_LIBRARIES/core-lambda-stubs_intermediates/classes-header.jar    -d out/target/common/obj/JAVA_LIBRARIES/svclib_intermediates/classes -s out/target/common/obj/JAVA_LIBRARIES/svclib_intermediates/anno  -source 1.8 -target 1.8 -g:source,lines  \\@out/target/common/obj/JAVA_LIBRARIES/svclib_intermediates/java-source-list  || ( rm -rf out/target/common/obj/JAVA_LIBRARIES/svclib_intermediates/classes ; exit 41 ) fi ) && (prebuilts/jdk/jdk9/linux-x86/bin/jar -cf out/target/common/obj/JAVA_LIBRARIES/svclib_intermediates/classes-full-debug.jar     @<(find out/target/common/obj/JAVA_LIBRARIES/svclib_intermediates/classes -type f | sort | build/soong/scripts/jar-args.sh out/target/common/obj/JAVA_LIBRARIES/svclib_intermediates/classes; echo \"-C out/empty .\") )"

/bin/bash -c "out/soong/host/linux-x86/bin/merge_zips -j --ignore-duplicates              -stripDir META-INF -zipToNotStrip out/target/common/obj/JAVA_LIBRARIES/svclib_intermediates/classes-full-debug.jar             out/target/common/obj/JAVA_LIBRARIES/svclib_intermediates/classes-combined.jar out/target/common/obj/JAVA_LIBRARIES/svclib_intermediates/classes-full-debug.jar"

/bin/bash -c "(rm -f out/target/common/obj/JAVA_LIBRARIES/svclib_intermediates/classes.jar ) && (cp \"out/target/common/obj/JAVA_LIBRARIES/svclib_intermediates/classes-combined.jar\" \"out/target/common/obj/JAVA_LIBRARIES/svclib_intermediates/classes.jar\" )"

/bin/bash -c "(rm -f out/target/common/obj/JAVA_LIBRARIES/svclib_intermediates/dex/classes*.dex out/target/common/obj/JAVA_LIBRARIES/svclib_intermediates/dex/d8_input.jar ) && (out/soong/host/linux-x86/bin/zip2zip -j -i out/target/common/obj/JAVA_LIBRARIES/svclib_intermediates/classes.jar -o out/target/common/obj/JAVA_LIBRARIES/svclib_intermediates/dex/d8_input.jar \"**/*.class\" ) && (out/soong/host/linux-x86/bin/d8 -JXms16M -JXmx2048M --output out/target/common/obj/JAVA_LIBRARIES/svclib_intermediates/dex/ --min-api 28   out/target/common/obj/JAVA_LIBRARIES/svclib_intermediates/dex/d8_input.jar ) && (rm -f out/target/common/obj/JAVA_LIBRARIES/svclib_intermediates/dex/d8_input.jar )"

/bin/bash -c "(rm -f out/target/common/obj/JAVA_LIBRARIES/svclib_intermediates//classes*.dex ) && (cp -fp out/target/common/obj/JAVA_LIBRARIES/svclib_intermediates/dex//classes*.dex out/target/common/obj/JAVA_LIBRARIES/svclib_intermediates/ )"

/bin/bash -c "(cp -f out/target/common/obj/JAVA_LIBRARIES/svclib_intermediates/classes.jar out/target/common/obj/JAVA_LIBRARIES/svclib_intermediates/javalib.jar.tmp ) && (zip -qd out/target/common/obj/JAVA_LIBRARIES/svclib_intermediates/javalib.jar.tmp \"*.class\" \"*/\" || true ) && (find out/target/common/obj/JAVA_LIBRARIES/svclib_intermediates/ -maxdepth 1 -name \"classes*.dex\" | sort | xargs zip -qjX out/target/common/obj/JAVA_LIBRARIES/svclib_intermediates/javalib.jar.tmp ) && (prebuilts/build-tools/linux-x86/bin/ziptime out/target/common/obj/JAVA_LIBRARIES/svclib_intermediates/javalib.jar.tmp ) && (if cmp -s out/target/common/obj/JAVA_LIBRARIES/svclib_intermediates/javalib.jar.tmp out/target/common/obj/JAVA_LIBRARIES/svclib_intermediates/javalib.jar ; then rm out/target/common/obj/JAVA_LIBRARIES/svclib_intermediates/javalib.jar.tmp ; else mv out/target/common/obj/JAVA_LIBRARIES/svclib_intermediates/javalib.jar.tmp out/target/common/obj/JAVA_LIBRARIES/svclib_intermediates/javalib.jar ; fi )"

/bin/bash -c "(rm -f out/target/product/morgan3g/obj/JAVA_LIBRARIES/svclib_intermediates/javalib.jar ) && (cp \"out/target/common/obj/JAVA_LIBRARIES/svclib_intermediates/javalib.jar\" \"out/target/product/morgan3g/obj/JAVA_LIBRARIES/svclib_intermediates/javalib.jar\" ) && (if (zipinfo out/target/product/morgan3g/obj/JAVA_LIBRARIES/svclib_intermediates/javalib.jar '*.dex' 2>/dev/null | grep -v ' stor ' >/dev/null) ; then zip --quiet --delete out/target/product/morgan3g/obj/JAVA_LIBRARIES/svclib_intermediates/javalib.jar classes.dex; dex_index=2; while zip --quiet --delete out/target/product/morgan3g/obj/JAVA_LIBRARIES/svclib_intermediates/javalib.jar classes\${dex_index}.dex > /dev/null; do let dex_index=dex_index+1; done fi )"

/bin/bash -c "(rm -f out/target/product/morgan3g/system/framework/svc.jar ) && (cp out/target/product/morgan3g/obj/JAVA_LIBRARIES/svclib_intermediates/javalib.jar out/target/product/morgan3g/system/framework/svc.jar )"

/bin/bash -c "(rm -f out/target/product/morgan3g/obj/JAVA_LIBRARIES/svclib_intermediates/oat/arm/javalib.odex ) && (mkdir -p out/target/product/morgan3g/obj/JAVA_LIBRARIES/svclib_intermediates/oat/arm/ ) && (stored_class_loader_context_libs= && class_loader_context_arg=--class-loader-context=\\& && class_loader_context=\\& && stored_class_loader_context_arg=\"\" && uses_library_names=\"\" && optional_uses_library_names=\"\" &&  ANDROID_LOG_TAGS=\"*:e\" out/host/linux-x86/bin/dex2oatd --runtime-arg -Xms64m --runtime-arg -Xmx512m \${class_loader_context_arg} \${stored_class_loader_context_arg} --boot-image=out/target/product/morgan3g/dex_bootjars/system/framework/boot.art --dex-file=out/target/common/obj/JAVA_LIBRARIES/svclib_intermediates/javalib.jar --dex-location=/system/framework/svc.jar --oat-file=out/target/product/morgan3g/obj/JAVA_LIBRARIES/svclib_intermediates/oat/arm/javalib.odex --android-root=out/target/product/morgan3g/system --instruction-set=arm --instruction-set-variant=cortex-a7 --instruction-set-features=default --runtime-arg -Xnorelocate --compile-pic --no-generate-debug-info --generate-build-id --abort-on-hard-verifier-error --force-determinism --no-inline-from=core-oj.jar  --compiler-filter=quicken --generate-mini-debug-info --compilation-reason=prebuilt )"

/bin/bash -c "(rm -f out/target/product/morgan3g/system/framework/oat/arm/svc.odex ) && (cp \"out/target/product/morgan3g/obj/JAVA_LIBRARIES/svclib_intermediates/oat/arm/javalib.odex\" \"out/target/product/morgan3g/system/framework/oat/arm/svc.odex\" )"

/bin/bash -c "(rm -f out/target/product/morgan3g/system/framework/oat/arm/svc.vdex ) && (cp \"out/target/product/morgan3g/obj/JAVA_LIBRARIES/svclib_intermediates/oat/arm/javalib.vdex\" \"out/target/product/morgan3g/system/framework/oat/arm/svc.vdex\" )"

/bin/bash -c "(rm -f out/target/product/morgan3g/system/bin/svc ) && (cp out/target/product/morgan3g/obj/EXECUTABLES/svc_intermediates/svc out/target/product/morgan3g/system/bin/svc )"


a push out/target/product/morgan3g/system/framework/oat/arm/svc.odex /system/framework/oat/arm/svc.odex;a push out/target/product/morgan3g/system/framework/oat/arm/svc.vdex  /system/framework/oat/arm/svc.vdex; a push out/target/product/morgan3g/system/framework/svc.jar  /system/framework/svc.jar