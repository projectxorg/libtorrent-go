#include "libtorrent/config.hpp"
#include "libtorrent/peer_connection.hpp"
#include "libtorrent/bt_peer_connection.hpp"
#include "libtorrent/peer_connection_handle.hpp"
#include "libtorrent/bencode.hpp"
#include "libtorrent/torrent.hpp"
#include "libtorrent/torrent_handle.hpp"
#include "libtorrent/extensions.hpp"

#include "upload_plugin.hpp"

#ifndef TORRENT_DISABLE_EXTENSIONS

#include "libtorrent/aux_/disable_warnings_push.hpp"

#include <boost/shared_ptr.hpp>

#include "libtorrent/aux_/disable_warnings_pop.hpp"

namespace libtorrent { namespace
{
	struct upload_plugin TORRENT_FINAL
		: torrent_plugin
	{
		upload_plugin(torrent& t)
			: m_torrent(t) {}

		virtual boost::shared_ptr<peer_plugin> new_connection(
			peer_connection_handle const& pc) TORRENT_OVERRIDE;

	private:
		torrent& m_torrent;

		// explicitly disallow assignment, to silence msvc warning
		upload_plugin& operator=(upload_plugin const&);
	};

	struct upload_peer_plugin TORRENT_FINAL
		: peer_plugin
	{
		upload_peer_plugin(torrent& t, peer_connection& pc, upload_plugin& tp)
			: m_torrent(t)
			, m_tp(tp)
			, m_pc(pc)
			// , m_last_msg(min_time())
			// , m_message_index(0)
			// , m_first_time(true)
		{}

		virtual char const* type() const TORRENT_OVERRIDE { return "upload"; }

		// virtual bool on_have(int index) { 
		// 	return true; 
		// }

		// virtual bool on_dont_have(int index) { 
		// 	return true; 
		// }
		
		// virtual bool on_bitfield(bitfield const&) {
		// 	return true; 
		// }
		
		// virtual bool on_have_all() { 
		// 	return true;
		// }
		
		// virtual bool on_have_none() { 
		// 	return true; 
		// }
		
		// virtual bool on_request(peer_request const&) { 
		// 	return true; 
		// }

		torrent& m_torrent;
		peer_connection& m_pc;
		upload_plugin& m_tp;

		upload_peer_plugin& operator=(upload_peer_plugin const&);
	};

	boost::shared_ptr<peer_plugin> upload_plugin::new_connection(peer_connection_handle const& pc)
	{
		if (pc.type() != peer_connection::bittorrent_connection)
			return boost::shared_ptr<peer_plugin>();

		return boost::shared_ptr<peer_plugin>(new upload_peer_plugin(m_torrent
			, *pc.native_handle(), *this));
	}
} }

namespace libtorrent
{
	boost::shared_ptr<torrent_plugin> create_upload_plugin(torrent_handle const& th, void*)
	{
		torrent* t = th.native_handle().get();
		return boost::shared_ptr<torrent_plugin>(new upload_plugin(*t));
	}
}

#endif

