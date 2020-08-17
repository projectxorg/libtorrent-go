// +build android

package libtorrent

// #cgo pkg-config: --static libtorrent-rasterbar openssl
// #cgo android CXXFLAGS: -Wno-macro-redefined -Wno-delete-non-virtual-dtor
// #cgo android LDFLAGS: -lm -lc++_shared -ldl
import "C"
