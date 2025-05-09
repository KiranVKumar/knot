noinst_LTLIBRARIES += libcontrib.la

libcontrib_la_CPPFLAGS = $(AM_CPPFLAGS) $(CFLAG_VISIBILITY) ${fuzzer_CFLAGS}
libcontrib_la_LDFLAGS  = $(AM_LDFLAGS) $(LDFLAG_EXCLUDE_LIBS) ${fuzzer_CFLAGS}
libcontrib_la_LIBADD   = $(pthread_LIBS)
libcontrib_LIBS        = libcontrib.la
if USE_GNUTLS_MEMSET
libcontrib_la_CPPFLAGS += $(gnutls_CFLAGS)
libcontrib_LIBS        += $(gnutls_LIBS)
endif USE_GNUTLS_MEMSET

EXTRA_DIST += \
	contrib/licenses/0BSD			\
	contrib/licenses/BSD-3-Clause		\
	contrib/licenses/LGPL-2.0		\
	contrib/licenses/LGPL-2.1		\
	contrib/libbpf/LICENSE			\
	contrib/openbsd/LICENSE			\
	contrib/ucw/LICENSE			\
	contrib/url-parser/LICENSE		\
	contrib/url-parser/README.md		\
	contrib/dnstap/dnstap.proto

libcontrib_la_SOURCES = \
	contrib/asan.h				\
	contrib/base32hex.c			\
	contrib/base32hex.h			\
	contrib/base64.c			\
	contrib/base64.h			\
	contrib/base64url.c			\
	contrib/base64url.h			\
	contrib/color.h				\
	contrib/ctype.h				\
	contrib/files.c				\
	contrib/files.h				\
	contrib/getline.c			\
	contrib/getline.h			\
	contrib/macros.h			\
	contrib/mempattern.c			\
	contrib/mempattern.h			\
	contrib/net.c				\
	contrib/net.h				\
	contrib/os.h				\
	contrib/qp-trie/trie.c			\
	contrib/qp-trie/trie.h			\
	contrib/semaphore.c			\
	contrib/semaphore.h			\
	contrib/sockaddr.c			\
	contrib/sockaddr.h			\
	contrib/spinlock.h			\
	contrib/string.c			\
	contrib/string.h			\
	contrib/strtonum.h			\
	contrib/time.c				\
	contrib/time.h				\
	contrib/tolower.h			\
	contrib/trim.h				\
	contrib/wire_ctx.h			\
	contrib/memcheck.h			\
	contrib/openbsd/siphash.c		\
	contrib/openbsd/siphash.h		\
	contrib/openbsd/strlcat.c		\
	contrib/openbsd/strlcat.h		\
	contrib/openbsd/strlcpy.c		\
	contrib/openbsd/strlcpy.h		\
	contrib/ucw/array-sort.h		\
	contrib/ucw/binsearch.h			\
	contrib/ucw/heap.c			\
	contrib/ucw/heap.h			\
	contrib/ucw/lists.c			\
	contrib/ucw/lists.h			\
	contrib/ucw/mempool.c			\
	contrib/ucw/mempool.h			\
	contrib/url-parser/url_parser.c		\
	contrib/url-parser/url_parser.h		\
	contrib/vpool/vpool.c			\
	contrib/vpool/vpool.h

if EMBEDDED_LIBBPF
noinst_LTLIBRARIES += libembbpf.la

libembbpf_la_CPPFLAGS = $(AM_CPPFLAGS) $(CFLAG_VISIBILITY) $(embedded_libbpf_CFLAGS)
libembbpf_la_LDFLAGS  = $(AM_LDFLAGS) $(LDFLAG_EXCLUDE_LIBS)
libembbpf_LIBS        = libembbpf.la $(embedded_libbpf_LIBS)

libembbpf_la_SOURCES = \
	contrib/libbpf/include/asm/barrier.h		\
	contrib/libbpf/include/linux/compiler.h		\
	contrib/libbpf/include/linux/err.h		\
	contrib/libbpf/include/linux/filter.h		\
	contrib/libbpf/include/linux/kernel.h		\
	contrib/libbpf/include/linux/list.h		\
	contrib/libbpf/include/linux/overflow.h		\
	contrib/libbpf/include/linux/ring_buffer.h	\
	contrib/libbpf/include/linux/types.h		\
	contrib/libbpf/include/uapi/linux/bpf_common.h	\
	contrib/libbpf/include/uapi/linux/bpf.h		\
	contrib/libbpf/include/uapi/linux/btf.h		\
	contrib/libbpf/include/uapi/linux/if_link.h	\
	contrib/libbpf/include/uapi/linux/if_xdp.h	\
	contrib/libbpf/include/uapi/linux/netlink.h	\
	contrib/libbpf/bpf/bpf.c			\
	contrib/libbpf/bpf/bpf.h			\
	contrib/libbpf/bpf/bpf_core_read.h		\
	contrib/libbpf/bpf/bpf_endian.h			\
	contrib/libbpf/bpf/bpf_helper_defs.h		\
	contrib/libbpf/bpf/bpf_helpers.h		\
	contrib/libbpf/bpf/bpf_prog_linfo.c		\
	contrib/libbpf/bpf/bpf_tracing.h		\
	contrib/libbpf/bpf/btf.c			\
	contrib/libbpf/bpf/btf.h			\
	contrib/libbpf/bpf/btf_dump.c			\
	contrib/libbpf/bpf/hashmap.c			\
	contrib/libbpf/bpf/hashmap.h			\
	contrib/libbpf/bpf/libbpf.c			\
	contrib/libbpf/bpf/libbpf.h			\
	contrib/libbpf/bpf/libbpf_errno.c		\
	contrib/libbpf/bpf/libbpf_internal.h		\
	contrib/libbpf/bpf/libbpf_probes.c		\
	contrib/libbpf/bpf/libbpf_util.h		\
	contrib/libbpf/bpf/netlink.c			\
	contrib/libbpf/bpf/nlattr.c			\
	contrib/libbpf/bpf/nlattr.h			\
	contrib/libbpf/bpf/str_error.c			\
	contrib/libbpf/bpf/str_error.h			\
	contrib/libbpf/bpf/xsk.c			\
	contrib/libbpf/bpf/xsk.h
endif EMBEDDED_LIBBPF

if HAVE_LIBDNSTAP
noinst_LTLIBRARIES += libdnstap.la

libdnstap_la_CPPFLAGS = $(AM_CPPFLAGS) $(CFLAG_VISIBILITY) $(DNSTAP_CFLAGS)
libdnstap_la_LDFLAGS  = $(AM_LDFLAGS) $(LDFLAG_EXCLUDE_LIBS)
libdnstap_LIBS        = libdnstap.la $(DNSTAP_LIBS)

SUFFIXES = .proto .pb-c.c .pb-c.h .c .pp

.proto.pb-c.c:
	$(AM_V_GEN)@PROTOC_C@ --c_out=. -I$(srcdir) $<

.proto.pb-c.h:
	$(AM_V_GEN)@PROTOC_C@ --c_out=. -I$(srcdir) $<

# Allows the creation of preprocessed file using "make <file-name-without-c>.pp"
.c.pp:
	$(COMPILE) -o $@ -E $<

libdnstap_la_SOURCES = \
	contrib/dnstap/convert.c	\
	contrib/dnstap/convert.h	\
	contrib/dnstap/dnstap.c		\
	contrib/dnstap/dnstap.h		\
	contrib/dnstap/message.c	\
	contrib/dnstap/message.h	\
	contrib/dnstap/reader.c		\
	contrib/dnstap/reader.h		\
	contrib/dnstap/writer.c		\
	contrib/dnstap/writer.h

nodist_libdnstap_la_SOURCES = \
	contrib/dnstap/dnstap.pb-c.c	\
	contrib/dnstap/dnstap.pb-c.h

BUILT_SOURCES += $(nodist_libdnstap_la_SOURCES)
CLEANFILES    += $(nodist_libdnstap_la_SOURCES)
endif HAVE_LIBDNSTAP
