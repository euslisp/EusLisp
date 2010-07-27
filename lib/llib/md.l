;;;; md.l
;;;; OpenSSL message digest interface
;;;; (c)2003 Toshihiro Matsui, AIST, Japan
;;;

(unless (find-package "EVP")  (make-package "EVP"))
(in-package "EVP")
(export '(Digest md5))

(setq md-module (load "/usr/lib/libssl.so"))

(defconstant MAX_MD_SIZE (+ 16 20)) ;;  /* The SSLv3 md5+sha1 type */

;; linux/i386 returned sizeof(EVP_MD_CTX)=152.
;; I chose 200 for the size of a context.

(defforeign OpenSSL_add_all_digests md-module "OpenSSL_add_all_digests" () :integer)
(defforeign MD_CTX_copy md-module "EVP_MD_CTX_copy" (:string :string) :integer)
(defforeign get_digestbyname md-module "EVP_get_digestbyname"
			(:string) :integer)
(defforeign DigestInit md-module "EVP_DigestInit" (:string :integer) :integer)
(defforeign DigestUpdate md-module "EVP_DigestUpdate"
			(:string :string :integer) :integer)
(defforeign DigestFinal md-module "EVP_DigestFinal"
			(:string :string :string) :integer)
(defforeign md_null md-module "EVP_md_null" () :integer)
(defforeign raw-md2 md-module "EVP_md2" () :string)
(defforeign raw-md5 md-module  "EVP_md5" () :string)
(defforeign raw-sha md-module "EVP_sha" () :string)
(defforeign raw-sha1 md-module "EVP_sha1" () :string)
(defforeign raw-dss md-module "EVP_dss" () :string)
(defforeign raw-dss1 md-module "EVP_dss1" () :string)
(defforeign raw-mdc2 md-module "EVP_mdc2" () :string)
(defforeign raw-ripemd160 md-module "EVP_ripemd160" () :integer)

(openssl_add_all_digests)

;; Digest
;; method may be "MD5", "SHA", "SHA1", "DSS", "DSS1", "MDC2", or "RIPEMD160"

(defun digest (method mesg)
   (let* ((md (get_digestbyname method))
	  (mdctx (make-string 200))
	  (result-buf (make-string 48))
	  (result-len (make-string 4)))
     (if (= 0 md)
	 (error "no such message digest method" method))
     (DigestInit mdctx md)
     (DigestUpdate mdctx mesg (length mesg))
     (DigestFinal mdctx result-buf result-len)
     (setq result-len (sys:peek result-len 0 :long))
     (with-output-to-string (s)
	(dotimes (i result-len)
	   (format s "~2,2x" (aref result-buf i)))
	(get-output-stream-string s))
     )
  )
   

(defun md5 (mesg) (digest "MD5") mesg)

