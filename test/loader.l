(require :unittest "lib/llib/unittest.l")

(init-unit-test)

;; check because ldmodule have #if ARM for objname, handle
(deftest test-load
  (let ((libpath (format nil "~A/~A/lib/libeusgeo.so" *eusdir*
                         (cond ((member :solaris2 *features*)  "SunOS5")
                               ((member :irix *features*) "IRIX")
                               ((member :irix6 *features*) "IRIX6")
                               ((member :darwin *features*) "Darwin")
                               ((member :sh4 *features*) "LinuxSH4")
                               ((member :linux *features*)
                                (cond
                                 ((member :x86_64 *features*)
                                  "Linux64")
                                 ((member :arm *features*)
                                  "LinuxARM")
                                 (t "Linux")))
                               ((member :SunOS4.1 *features*) "SunOS4")
                               ((member :Windows *features*) "Windows")
                               ((member :Windows95 *features*) "Win95")
                               ((member :WindowsNT *features*) "WinNT")
                               ((member :alpha *features*) "Alpha")
                               ((member :cygwin *features*) "Cygwin"))))
        libmod)
    (format *error-output* "loading ~A~%" libpath)
    (setq libmod (load libpath :entry nil))
    (format *error-output* "loaded ~A, object-file ~A~%" libmod (load-module-object-file libmod))
    (assert (equal (pathname (load-module-object-file libmod)) (pathname libpath)) (format nil "object-file path ~A ~A" (load-module-object-file libmod) libpath))
    ))

;; cehck because closure have #if ARM for euv0, euv1, euv2
(eval-when (load eval)
  (run-all-tests)
  (exit))
