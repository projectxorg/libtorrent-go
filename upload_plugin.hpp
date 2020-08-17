#ifndef TORRENT_UPLOAD_HPP_INCLUDED
#define TORRENT_UPLOAD_HPP_INCLUDED

#ifndef TORRENT_DISABLE_EXTENSIONS

#include "libtorrent/aux_/disable_warnings_push.hpp"

#include <boost/shared_ptr.hpp>
#include "libtorrent/config.hpp"

#include "libtorrent/aux_/disable_warnings_pop.hpp"

namespace libtorrent
{
	struct torrent_plugin;
	struct torrent_handle;

	TORRENT_EXPORT boost::shared_ptr<torrent_plugin> create_upload_plugin(torrent_handle const&, void*);
}

#endif // TORRENT_DISABLE_EXTENSIONS

#endif // TORRENT_UPLOAD_HPP_INCLUDED

