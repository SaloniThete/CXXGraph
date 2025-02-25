/***********************************************************/
/***      ______  ____  ______                 _         ***/
/***     / ___\ \/ /\ \/ / ___|_ __ __ _ _ __ | |__	     ***/
/***    | |    \  /  \  / |  _| '__/ _` | '_ \| '_ \	 ***/
/***    | |___ /  \  /  \ |_| | | | (_| | |_) | | | |    ***/
/***     \____/_/\_\/_/\_\____|_|  \__,_| .__/|_| |_|    ***/
/***                                    |_|			     ***/
/***********************************************************/
/***     Header-Only C++ Library for Graph			     ***/
/***	 Representation and Algorithms				     ***/
/***********************************************************/
/***     Author: ZigRazor			     			     ***/
/***	 E-Mail: zigrazor@gmail.com 				     ***/
/***********************************************************/
/***	 Collaboration: ----------- 				     ***/
/***********************************************************/
/***	 License: AGPL v3.0							     ***/
/***********************************************************/

#ifndef __UNDIRECTEDWEIGHTEDEDGE_H__
#define __UNDIRECTEDWEIGHTEDEDGE_H__

#pragma once

#include "UndirectedEdge.hpp"
#include "Weighted.hpp"

namespace CXXGRAPH
{
    //Foward Declaration
    template <typename T>
	class DirectedWeightedEdge;

	template <typename T>
	class UndirectedWeightedEdge;

	// ostream operator
	template <typename T>
	std::ostream &operator<<(std::ostream &o, const UndirectedWeightedEdge<T> &edge);

    template <typename T>
	class UndirectedWeightedEdge : public UndirectedEdge<T>, public Weighted
	{
	public:
		UndirectedWeightedEdge(const unsigned long id, const Node<T> &node1, const Node<T> &node2, const double weight);
		UndirectedWeightedEdge(const unsigned long id, const std::pair<const Node<T> *, const Node<T> *> &nodepair, const double weight);
		UndirectedWeightedEdge(const UndirectedEdge<T> &edge, const double weight);
		UndirectedWeightedEdge(const Edge<T> &edge, const double weight);
		UndirectedWeightedEdge(const UndirectedEdge<T> &edge);
		UndirectedWeightedEdge(const Edge<T> &edge);
		UndirectedWeightedEdge(const DirectedWeightedEdge<T> &edge);
		virtual ~UndirectedWeightedEdge() = default;
		const std::optional<bool> isWeighted() const override;
		//operator
		explicit operator DirectedWeightedEdge<T>() const { return DirectedWeightedEdge<T>(Edge<T>::getId(), Edge<T>::getNodePair(), Weighted::getWeight()); }

		friend std::ostream &operator<<<>(std::ostream &os, const UndirectedWeightedEdge<T> &edge);
	};

	template <typename T>
	UndirectedWeightedEdge<T>::UndirectedWeightedEdge(const unsigned long id, const Node<T> &node1, const Node<T> &node2, const double weight) : UndirectedEdge<T>(id, node1, node2), Weighted(weight)
	{
	}

	template <typename T>
	UndirectedWeightedEdge<T>::UndirectedWeightedEdge(const unsigned long id, const std::pair<const Node<T> *, const Node<T> *> &nodepair, const double weight) : UndirectedEdge<T>(id, nodepair), Weighted(weight)
	{
	}

	template <typename T>
	UndirectedWeightedEdge<T>::UndirectedWeightedEdge(const UndirectedEdge<T> &edge, const double weight) : UndirectedEdge<T>(edge), Weighted(weight)
	{
	}

	template <typename T>
	UndirectedWeightedEdge<T>::UndirectedWeightedEdge(const Edge<T> &edge, const double weight) : UndirectedEdge<T>(edge), Weighted(weight)
	{
	}

	template <typename T>
	UndirectedWeightedEdge<T>::UndirectedWeightedEdge(const UndirectedEdge<T> &edge) : UndirectedEdge<T>(edge), Weighted()
	{
	}

	template <typename T>
	UndirectedWeightedEdge<T>::UndirectedWeightedEdge(const Edge<T> &edge) : UndirectedEdge<T>(edge), Weighted()
	{
	}

	template <typename T>
	UndirectedWeightedEdge<T>::UndirectedWeightedEdge(const DirectedWeightedEdge<T> &edge) : UndirectedEdge<T>(edge), Weighted(edge.getWeight())
	{
	}

	template <typename T>
	const std::optional<bool> UndirectedWeightedEdge<T>::isWeighted() const
	{
		return true;
	}

	template <typename T>
	std::ostream &operator<<(std::ostream &os, const UndirectedWeightedEdge<T> &edge)
	{
		os << "((Node: " << edge.getNode1().getId() << ")) <----- |Edge: #" << edge.getId() << " W:" << edge.getWeight() << "|-----> ((Node: " << edge.getNode2().getId() << "))";
		return os;
	}

}

#endif // __UNDIRECTEDWEIGHTEDEDGE_H__