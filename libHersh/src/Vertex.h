/*
 * Vertex.h
 *
 *  Created on: Aug 12, 2014
 *      Author: john
 */

#ifndef VERTEX_H_
#define VERTEX_H_

namespace hersh
{
class Vertex
{
	public:
		Vertex( float x, float y );
		virtual ~Vertex();
		float getX();
		float getY();
		void scale( float s );
		void translate( float x, float y );
		void setX( const float value );
		void setY( const float value );

	private:
		float _x, _y;
};

} //namespace Hersh
#endif /* VERTEX_H_ */
