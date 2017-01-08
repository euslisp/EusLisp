(unless (boundp '*testmod*)
  (setq *testmod* (load-foreign "test_foreign.so"))
  (defforeign float-test *testmod* "float_test" (:integer :float32 :float32 :float32 :float32) :integer)
  (defforeign float2-test *testmod* "float_test" (:integer :double :double :double :double) :integer)
  (defforeign float3-test *testmod* "float_test" () :integer)
  (defforeign double-test *testmod* "double_test" (:integer :double :double :double :double) :integer)
  (defforeign double2-test *testmod* "double_test" (:integer :float32 :float32 :float32 :float32) :integer)
  (defforeign double3-test *testmod* "double_test" () :integer)
  (defforeign iv-test *testmod* "iv_test" () :integer)
  (defforeign lv-test *testmod* "lv_test" () :integer)
  (defforeign fv-test *testmod* "fv_test" () :integer)
  (defforeign dv-test *testmod* "dv_test" () :integer)
  (defforeign str-test *testmod* "str_test" () :integer)
  (defforeign int-test *testmod* "int_test" () :integer)
  (defforeign ret-float *testmod* "ret_float" () :float32)
  (defforeign ret-double *testmod* "ret_double" () :float)
  (defforeign ret-long *testmod* "ret_long" () :integer)
  
  (defforeign set-ifunc *testmod* "set_ifunc" (:integer) :integer)
  (defforeign set-ffunc *testmod* "set_ffunc" (:integer) :integer)

  (defforeign test-testd *testmod* "test_testd" (:integer :integer :integer
                                                          :integer :integer :integer
                                                          :double :double :double :double
                                                          :double :double :double :double
                                                          :double :double
                                                          :integer :integer) :float)
  (defforeign call-ifunc *testmod* "call_ifunc" () :integer)
  (defforeign call-ffunc *testmod* "call_ffunc" () :float)

  (defforeign get-size-pointer *testmod* "get_size_of_pointer" () :integer)
  (defforeign get-size-float32 *testmod* "get_size_of_float32" () :integer)
  (defforeign get-size-double  *testmod* "get_size_of_double" ()  :integer)
  (defforeign get-size-long    *testmod* "get_size_of_long" () :integer)
  (defforeign get-size-int     *testmod* "get_size_of_int" () :integer)
  )


