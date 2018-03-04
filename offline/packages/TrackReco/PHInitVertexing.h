/*!
 *  \file		PHInitVertexing.h
 *  \brief		Base class for inital vertexing
 *  \author		Haiwang Yu <yuhw@nmsu.edu>
 */

#ifndef __H_PHInitVertexing_H__
#define __H_PHInitVertexing_H__

// PHENIX includes
#include <fun4all/SubsysReco.h>

// STL includes
#include <string>

// forward declarations
class PHCompositeNode;

class SvtxClusterMap;
class SvtxVertexMap;

/// \class PHInitVertexing
///
/// \brief Base class for inital vertexing
///
class PHInitVertexing : public SubsysReco
{

 public:

  PHInitVertexing(const std::string &name = "PHInitVertexing");
  virtual ~PHInitVertexing() {}

  int Init(PHCompositeNode *topNode);
  int InitRun(PHCompositeNode *topNode);
  int process_event(PHCompositeNode *topNode);
  int End(PHCompositeNode *topNode);

 protected:
  /// setup interface for trackers, called in InitRun, setup things like pointers to nodes.
  /// overrided in derived classes
  virtual int Setup(PHCompositeNode *topNode);

  /// process event interface for trackers, called in process_event.
  /// implemented in derived classes
  virtual int Process() = 0;

  SvtxClusterMap *_cluster_map;
  SvtxVertexMap *_vertex_map;

 private:

	/// create new node output pointers
	int CreateNodes(PHCompositeNode *topNode);

	/// fetch node pointers
	int GetNodes(PHCompositeNode *topNode);
};

#endif // __H_PHInitVertexing_H__
