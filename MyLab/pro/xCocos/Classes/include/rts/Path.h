/*
 * Copyright (C) 2005-2008 MaNGOS <http://www.mangosproject.org/>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#ifndef MANGOSSERVER_PATH_H
#define MANGOSSERVER_PATH_H

// #include "Define.h"
#include <vector>

class Path
{
    public:
        struct PathNode
        {
            float x,y,z;
            uint32 time;
        };

        void SetLength(const unsigned int sz)
        {
            i_nodes.resize( sz );
        }

        unsigned int Size() const { return i_nodes.size(); }
        unsigned int size() const { return i_nodes.size(); }
        bool Empty() const { return i_nodes.empty(); }
        bool empty() const { return i_nodes.empty(); }
        void Resize(unsigned int sz) { i_nodes.resize(sz); }
        void resize(unsigned int sz) { i_nodes.resize(sz); }
        void Clear(void) { i_nodes.clear(); }
        void clear(void) { i_nodes.clear(); }
        PathNode const* GetNodes(uint32 start = 0) const { return &i_nodes[start]; }
        float GetTotalLength() const { return GetTotalLength(0,Size()); }
        float GetTotalLength(uint32 start, uint32 end) const
        {
            float len = 0, xd, yd, zd;
            for(unsigned int idx=start+1; idx < end; ++idx)
            {
                xd = i_nodes[ idx ].x - i_nodes[ idx-1 ].x;
                yd = i_nodes[ idx ].y - i_nodes[ idx-1 ].y;
                zd = i_nodes[ idx ].z - i_nodes[ idx-1 ].z;
                len += sqrtf( xd*xd + yd*yd + zd*zd );
            }
            return len;
        }

        float GetPassedLength(uint32 curnode, float x, float y, float z)
        {
            float len = 0, xd, yd, zd;
            for(unsigned int idx=1; idx < curnode; ++idx)
            {
                xd = i_nodes[ idx ].x - i_nodes[ idx-1 ].x;
                yd = i_nodes[ idx ].y - i_nodes[ idx-1 ].y;
                zd = i_nodes[ idx ].z - i_nodes[ idx-1 ].z;
                len += sqrtf( xd*xd + yd*yd + zd*zd );
            }

            if(curnode > 0)
            {
                xd = x - i_nodes[curnode-1].x;
                yd = y - i_nodes[curnode-1].y;
                zd = z - i_nodes[curnode-1].z;
                len += sqrtf( xd*xd + yd*yd + zd*zd );
            }

            return len;
        }

        void Add(float x,float y,float z,uint32 time)
        {
            PathNode node;
            node.x = x;
            node.y = y;
            node.z = z;
            node.time = time;
            i_nodes.push_back(node);
        }

        PathNode& operator[](const unsigned int idx) { return i_nodes[idx]; }
        const PathNode& operator()(const unsigned int idx) const { return i_nodes[idx]; }
        PathNode& at(const unsigned int idx) { return i_nodes[idx]; }
    protected:
        std::vector<PathNode> i_nodes;
};



class PathMove : public Path
{
public:
    PathMove(void)
    {
        Clear();
    }
    bool UpdateNode(uint32 diff)
    {
        if (Empty()) return false;
        CheckStart();
        if (m_curNode >= i_nodes.size())
        {
            return false;
        }

        m_totalTime+=diff;
        unsigned int nodeCount = Size();
        for (m_curNode;m_curNode<nodeCount;++m_curNode)
        {
            uint32 overTime = m_totalTime-m_nodeTime;

            //到达终点
            if ((m_curNode+1)>=nodeCount)
            {
                m_curX = i_nodes[m_curNode].x;
                m_curY = i_nodes[m_curNode].y;
                m_curZ = i_nodes[m_curNode].z;
                continue;
            }

            if (i_nodes[m_curNode+1].time<overTime)
            {
                //超过当前节点
                m_nodeTime += i_nodes[m_curNode+1].time;
            }
            else
            {
                //节点内移动
                //计算当前节点偏移
                float fx = i_nodes[m_curNode].x;
                float fy = i_nodes[m_curNode].y;
                float fz = i_nodes[m_curNode].z;
                float dx = i_nodes[m_curNode+1].x;
                float dy = i_nodes[m_curNode+1].y;
                float dz = i_nodes[m_curNode+1].z;
                float percent_passed = (float)overTime / (float)i_nodes[m_curNode+1].time;
                m_curX = fx + ((dx - fx) * percent_passed);
                m_curY = fy + ((dy - fy) * percent_passed);
                m_curZ = fz + ((dz - fz) * percent_passed);
                break;
            }
        }
        return true;
    }

    bool GetFuturePos(uint32 time,float& newX,float& newY,float& newZ) const
    {
        if (Empty()) return false;
        uint32 curNode = m_curNode;
        if (m_curNode == UINT_MAX)
            curNode=0;
        if (m_curNode >= i_nodes.size())
        {
            const PathNode& node = *i_nodes.rbegin();
            newX = node.x;
            newY = node.y;
            newZ = node.z;
            return true;
        }
        uint32 totalTime = m_totalTime+time;
        uint32 nodeTime = m_nodeTime;
        unsigned int nodeCount = Size();
        for (curNode;curNode<nodeCount;++curNode)
        {
            uint32 overTime = totalTime-nodeTime;

            //到达终点
            if ((curNode+1)>=nodeCount)
            {
                newX = i_nodes[curNode].x;
                newY = i_nodes[curNode].y;
                newZ = i_nodes[curNode].z;
                continue;
            }

            if (i_nodes[curNode+1].time<overTime)
            {
                //超过当前节点
                nodeTime += i_nodes[curNode+1].time;
            }
            else
            {
                //节点内移动
                //计算当前节点偏移
                float fx = i_nodes[curNode].x;
                float fy = i_nodes[curNode].y;
                float fz = i_nodes[curNode].z;
                float dx = i_nodes[curNode+1].x;
                float dy = i_nodes[curNode+1].y;
                float dz = i_nodes[curNode+1].z;
                float percent_passed = (float)overTime / (float)i_nodes[curNode+1].time;
                newX = fx + ((dx - fx) * percent_passed);
                newY = fy + ((dy - fy) * percent_passed);
                newZ = fz + ((dz - fz) * percent_passed);
                break;
            }
        }
        return true;
    }

    bool IsValid() const {return !Empty();}
    void GetCurPos(float& x,float& y,float& z) const {x=m_curX;y=m_curY;z=m_curZ;}
    bool Arrived() const {return (IsValid()&&(m_curNode+1)>=Size());}
    void Clear()
    {
        Path::Clear();
        m_curNode=UINT_MAX;
        m_totalTime = 0;
        m_nodeTime = 0;
        m_curX=0.f;
        m_curY=0.f;
        m_curZ=0.f;
    }
    void clear(){return Clear();}
protected:
    unsigned int m_curNode;
    float m_curX;
    float m_curY;
    float m_curZ;
    uint32 m_totalTime;
    uint32 m_nodeTime;
    void CheckStart()
    {
        if (m_curNode == UINT_MAX)
        {
            m_curNode = 0;
            m_curX = i_nodes[0].x;
            m_curY = i_nodes[0].y;
            m_curZ = i_nodes[0].z;
        }
    }
};

#endif
