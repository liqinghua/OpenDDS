/*
 *
 *
 * Distributed under the OpenDDS License.
 * See: http://www.opendds.org/license.html
 */

#ifndef OPENDDS_DCPS_SECURITY_PLUGIN_INST_H
#define OPENDDS_DCPS_SECURITY_PLUGIN_INST_H

#include "dds/DCPS/dcps_export.h"
#include "dds/DCPS/RcObject_T.h"
#include "dds/DCPS/PoolAllocator.h"
#include "SecurityPluginInterfaces_rch.h"
#include "ace/Synch_Traits.h"

OPENDDS_BEGIN_VERSIONED_NAMESPACE_DECL

namespace OpenDDS {
namespace DCPS {

/**
 * @class SecurityPluginInst
 *
 * @brief Base class for concrete security plugins to provide new objects.
 *
 * Each security plugin implementation will need to define a concrete
 * subclass of the SecurityPluginType class.  The base
 * class contains the pure virtual functions to
 * provide new objects. The concrete plugin implements these methods
 * to provide the implementations of the various plugins.
 *
 */
class OpenDDS_Dcps_Export SecurityPluginInst : public RcObject<ACE_SYNCH_MUTEX> {
public:

	// Factory methods for the plugin specific interfaces.  A SecurityPluginInst
	// may not support creating all of these interfaces
  virtual Authentication_rch create_authentication() = 0;
  virtual AccessControl_rch create_access_control() = 0;
  virtual CryptoKeyExchange_rch create_crypto_key_exchange() = 0;
  virtual CryptoKeyFactory_rch create_crypto_key_factory() = 0;
  virtual CryptoTransform_rch create_crypto_transform() = 0;

  // Perform any logic needed when shutting down the plugin
  virtual void shutdown() = 0;

protected:

  SecurityPluginInst();
  virtual ~SecurityPluginInst();
};


} // namespace DCPS
} // namespace OpenDDS

OPENDDS_END_VERSIONED_NAMESPACE_DECL

#endif
