#include <stdio.h>
#include <GL/gl.h>
  
  main()
{
  
  printf(";;; Boolean values\n");
  printf("(defconstant GL_FALSE %d)\n", GL_FALSE);
  printf("(defconstant GL_TRUE %d)\n", GL_TRUE);
  printf("\n");
  
  
  printf(";;; Data types\n");
  printf("(defconstant GL_BYTE %d)\n", GL_BYTE);
  printf("(defconstant GL_UNSIGNED_BYTE %d)\n", GL_UNSIGNED_BYTE);
  printf("(defconstant GL_SHORT %d)\n", GL_SHORT);
  printf("(defconstant GL_UNSIGNED_SHORT %d)\n", GL_UNSIGNED_SHORT);
  printf("(defconstant GL_INT %d)\n", GL_INT);
  printf("(defconstant GL_UNSIGNED_INT %d)\n", GL_UNSIGNED_INT);
  printf("(defconstant GL_FLOAT %d)\n", GL_FLOAT);
  printf("(defconstant GL_2_BYTES %d)\n", GL_2_BYTES);
  printf("(defconstant GL_3_BYTES %d)\n", GL_3_BYTES);
  printf("(defconstant GL_4_BYTES %d)\n", GL_4_BYTES);
  printf("\n");
  
  
  printf(";;; Primitives\n");
  printf("(defconstant GL_LINES %d)\n", GL_LINES);
  printf("(defconstant GL_POINTS %d)\n", GL_POINTS);
  printf("(defconstant GL_LINE_STRIP %d)\n", GL_LINE_STRIP);
  printf("(defconstant GL_LINE_LOOP %d)\n", GL_LINE_LOOP);
  printf("(defconstant GL_TRIANGLES %d)\n", GL_TRIANGLES);
  printf("(defconstant GL_TRIANGLE_STRIP %d)\n", GL_TRIANGLE_STRIP);
  printf("(defconstant GL_TRIANGLE_FAN %d)\n", GL_TRIANGLE_FAN);
  printf("(defconstant GL_QUADS %d)\n", GL_QUADS);
  printf("(defconstant GL_QUAD_STRIP %d)\n", GL_QUAD_STRIP);
  printf("(defconstant GL_POLYGON %d)\n", GL_POLYGON);
  printf("(defconstant GL_EDGE_FLAG %d)\n", GL_EDGE_FLAG);
  printf("\n");
  
  
  printf(";;; Matrix Mode\n");
  printf("(defconstant GL_MATRIX_MODE %d)\n", GL_MATRIX_MODE);
  printf("(defconstant GL_MODELVIEW %d)\n", GL_MODELVIEW);
  printf("(defconstant GL_PROJECTION %d)\n", GL_PROJECTION);
  printf("(defconstant GL_TEXTURE %d)\n", GL_TEXTURE);
  printf("\n");
  
  
  printf(";;; Points\n");
  printf("(defconstant GL_POINT_SMOOTH %d)\n", GL_POINT_SMOOTH);
  printf("(defconstant GL_POINT_SIZE %d)\n", GL_POINT_SIZE);
  printf("(defconstant GL_POINT_SIZE_GRANULARITY %d)\n", GL_POINT_SIZE_GRANULARITY);
  printf("(defconstant GL_POINT_SIZE_RANGE %d)\n", GL_POINT_SIZE_RANGE);
  printf("\n");
  
  
  printf(";;; Lines\n");
  printf("(defconstant GL_LINE_SMOOTH %d)\n", GL_LINE_SMOOTH);
  printf("(defconstant GL_LINE_STIPPLE %d)\n", GL_LINE_STIPPLE);
  printf("(defconstant GL_LINE_STIPPLE_PATTERN %d)\n", GL_LINE_STIPPLE_PATTERN);
  printf("(defconstant GL_LINE_STIPPLE_REPEAT %d)\n", GL_LINE_STIPPLE_REPEAT);
  printf("(defconstant GL_LINE_WIDTH %d)\n", GL_LINE_WIDTH);
  printf("(defconstant GL_LINE_WIDTH_GRANULARITY %d)\n", GL_LINE_WIDTH_GRANULARITY);
  printf("(defconstant GL_LINE_WIDTH_RANGE %d)\n", GL_LINE_WIDTH_RANGE);
  printf("\n");
  
  
  printf(";;; Polygons\n");
  printf("(defconstant GL_POINT %d)\n", GL_POINT);
  printf("(defconstant GL_LINE %d)\n", GL_LINE);
  printf("(defconstant GL_FILL %d)\n", GL_FILL);
  printf("(defconstant GL_CCW %d)\n", GL_CCW);
  printf("(defconstant GL_CW %d)\n", GL_CW);
  printf("(defconstant GL_FRONT %d)\n", GL_FRONT);
  printf("(defconstant GL_BACK %d)\n", GL_BACK);
  printf("(defconstant GL_CULL_FACE %d)\n", GL_CULL_FACE);
  printf("(defconstant GL_CULL_FACE_MODE %d)\n", GL_CULL_FACE_MODE);
  printf("(defconstant GL_POLYGON_SMOOTH %d)\n", GL_POLYGON_SMOOTH);
  printf("(defconstant GL_POLYGON_STIPPLE %d)\n", GL_POLYGON_STIPPLE);
  printf("(defconstant GL_FRONT_FACE %d)\n", GL_FRONT_FACE);
  printf("(defconstant GL_POLYGON_MODE %d)\n", GL_POLYGON_MODE);
  printf("\n");
  
  
  printf(";;; Display Lists\n");
  printf("(defconstant GL_COMPILE %d)\n", GL_COMPILE);
  printf("(defconstant GL_COMPILE_AND_EXECUTE %d)\n", GL_COMPILE_AND_EXECUTE);
  printf("(defconstant GL_LIST_BASE %d)\n", GL_LIST_BASE);
  printf("(defconstant GL_LIST_INDEX %d)\n", GL_LIST_INDEX);
  printf("(defconstant GL_LIST_MODE %d)\n", GL_LIST_MODE);
  printf("\n");
  
  
  printf(";;; Depth buffer\n");
  printf("(defconstant GL_NEVER %d)\n", GL_NEVER);
  printf("(defconstant GL_LESS %d)\n", GL_LESS);
  printf("(defconstant GL_GEQUAL %d)\n", GL_GEQUAL);
  printf("(defconstant GL_LEQUAL %d)\n", GL_LEQUAL);
  printf("(defconstant GL_GREATER %d)\n", GL_GREATER);
  printf("(defconstant GL_NOTEQUAL %d)\n", GL_NOTEQUAL);
  printf("(defconstant GL_EQUAL %d)\n", GL_EQUAL);
  printf("(defconstant GL_ALWAYS %d)\n", GL_ALWAYS);
  printf("(defconstant GL_DEPTH_TEST %d)\n", GL_DEPTH_TEST);
  printf("(defconstant GL_DEPTH_BITS %d)\n", GL_DEPTH_BITS);
  printf("(defconstant GL_DEPTH_CLEAR_VALUE %d)\n", GL_DEPTH_CLEAR_VALUE);
  printf("(defconstant GL_DEPTH_FUNC %d)\n", GL_DEPTH_FUNC);
  printf("(defconstant GL_DEPTH_RANGE %d)\n", GL_DEPTH_RANGE);
  printf("(defconstant GL_DEPTH_WRITEMASK %d)\n", GL_DEPTH_WRITEMASK);
  printf("(defconstant GL_DEPTH_COMPONENT %d)\n", GL_DEPTH_COMPONENT);
  printf("\n");
  
  
  printf(";;; Lighting\n");
  printf("(defconstant GL_LIGHTING %d)\n", GL_LIGHTING);
  printf("(defconstant GL_LIGHT0 %d)\n", GL_LIGHT0);
  printf("(defconstant GL_LIGHT1 %d)\n", GL_LIGHT1);
  printf("(defconstant GL_LIGHT2 %d)\n", GL_LIGHT2);
  printf("(defconstant GL_LIGHT3 %d)\n", GL_LIGHT3);
  printf("(defconstant GL_LIGHT4 %d)\n", GL_LIGHT4);
  printf("(defconstant GL_LIGHT5 %d)\n", GL_LIGHT5);
  printf("(defconstant GL_LIGHT6 %d)\n", GL_LIGHT6);
  printf("(defconstant GL_LIGHT7 %d)\n", GL_LIGHT7);
  printf("(defconstant GL_SPOT_EXPONENT %d)\n", GL_SPOT_EXPONENT);
  printf("(defconstant GL_SPOT_CUTOFF %d)\n", GL_SPOT_CUTOFF);
  printf("(defconstant GL_CONSTANT_ATTENUATION %d)\n", GL_CONSTANT_ATTENUATION);
  printf("(defconstant GL_LINEAR_ATTENUATION %d)\n", GL_LINEAR_ATTENUATION);
  printf("(defconstant GL_QUADRATIC_ATTENUATION %d)\n", GL_QUADRATIC_ATTENUATION);
  printf("(defconstant GL_AMBIENT %d)\n", GL_AMBIENT);
  printf("(defconstant GL_DIFFUSE %d)\n", GL_DIFFUSE);
  printf("(defconstant GL_SPECULAR %d)\n", GL_SPECULAR);
  printf("(defconstant GL_SHININESS %d)\n", GL_SHININESS);
  printf("(defconstant GL_EMISSION %d)\n", GL_EMISSION);
  printf("(defconstant GL_POSITION %d)\n", GL_POSITION);
  printf("(defconstant GL_SPOT_DIRECTION %d)\n", GL_SPOT_DIRECTION);
  printf("(defconstant GL_AMBIENT_AND_DIFFUSE %d)\n", GL_AMBIENT_AND_DIFFUSE);
  printf("(defconstant GL_COLOR_INDEXES %d)\n", GL_COLOR_INDEXES);
  printf("(defconstant GL_LIGHT_MODEL_TWO_SIDE %d)\n", GL_LIGHT_MODEL_TWO_SIDE);
  printf("(defconstant GL_LIGHT_MODEL_LOCAL_VIEWER %d)\n", GL_LIGHT_MODEL_LOCAL_VIEWER);
  printf("(defconstant GL_LIGHT_MODEL_AMBIENT %d)\n", GL_LIGHT_MODEL_AMBIENT);
  printf("(defconstant GL_FRONT_AND_BACK %d)\n", GL_FRONT_AND_BACK);
  printf("(defconstant GL_SHADE_MODEL %d)\n", GL_SHADE_MODEL);
  printf("(defconstant GL_FLAT %d)\n", GL_FLAT);
  printf("(defconstant GL_SMOOTH %d)\n", GL_SMOOTH);
  printf("(defconstant GL_COLOR_MATERIAL %d)\n", GL_COLOR_MATERIAL);
  printf("(defconstant GL_COLOR_MATERIAL_FACE %d)\n", GL_COLOR_MATERIAL_FACE);
  printf("(defconstant GL_COLOR_MATERIAL_PARAMETER %d)\n", GL_COLOR_MATERIAL_PARAMETER);
  printf("(defconstant GL_NORMALIZE %d)\n", GL_NORMALIZE);
  printf("\n");
  
  
  printf(";;; User clipping planes\n");
  printf("(defconstant GL_CLIP_PLANE0 %d)\n", GL_CLIP_PLANE0);
  printf("(defconstant GL_CLIP_PLANE1 %d)\n", GL_CLIP_PLANE1);
  printf("(defconstant GL_CLIP_PLANE2 %d)\n", GL_CLIP_PLANE2);
  printf("(defconstant GL_CLIP_PLANE3 %d)\n", GL_CLIP_PLANE3);
  printf("(defconstant GL_CLIP_PLANE4 %d)\n", GL_CLIP_PLANE4);
  printf("(defconstant GL_CLIP_PLANE5 %d)\n", GL_CLIP_PLANE5);
  printf("\n");
  
  
  printf(";;; Accumulation buffer\n");
  printf("(defconstant GL_ACCUM_RED_BITS %d)\n", GL_ACCUM_RED_BITS);
  printf("(defconstant GL_ACCUM_GREEN_BITS %d)\n", GL_ACCUM_GREEN_BITS);
  printf("(defconstant GL_ACCUM_BLUE_BITS %d)\n", GL_ACCUM_BLUE_BITS);
  printf("(defconstant GL_ACCUM_ALPHA_BITS %d)\n", GL_ACCUM_ALPHA_BITS);
  printf("(defconstant GL_ACCUM_CLEAR_VALUE %d)\n", GL_ACCUM_CLEAR_VALUE);
  printf("(defconstant GL_ACCUM %d)\n", GL_ACCUM);
  printf("(defconstant GL_ADD %d)\n", GL_ADD);
  printf("(defconstant GL_LOAD %d)\n", GL_LOAD);
  printf("(defconstant GL_MULT %d)\n", GL_MULT);
  printf("(defconstant GL_RETURN %d)\n", GL_RETURN);
  printf("\n");
  
  
  printf(";;; Alpha testing\n");
  printf("(defconstant GL_ALPHA_TEST %d)\n", GL_ALPHA_TEST);
  printf("(defconstant GL_ALPHA_TEST_REF %d)\n", GL_ALPHA_TEST_REF);
  printf("(defconstant GL_ALPHA_TEST_FUNC %d)\n", GL_ALPHA_TEST_FUNC);
  printf("\n");
  
  
  printf(";;; Blending\n");
  printf("(defconstant GL_BLEND %d)\n", GL_BLEND);
  printf("(defconstant GL_BLEND_SRC %d)\n", GL_BLEND_SRC);
  printf("(defconstant GL_BLEND_DST %d)\n", GL_BLEND_DST);
  printf("(defconstant GL_ZERO %d)\n", GL_ZERO);
  printf("(defconstant GL_ONE %d)\n", GL_ONE);
  printf("(defconstant GL_SRC_COLOR %d)\n", GL_SRC_COLOR);
  printf("(defconstant GL_ONE_MINUS_SRC_COLOR %d)\n", GL_ONE_MINUS_SRC_COLOR);
  printf("(defconstant GL_DST_COLOR %d)\n", GL_DST_COLOR);
  printf("(defconstant GL_ONE_MINUS_DST_COLOR %d)\n", GL_ONE_MINUS_DST_COLOR);
  printf("(defconstant GL_SRC_ALPHA %d)\n", GL_SRC_ALPHA);
  printf("(defconstant GL_ONE_MINUS_SRC_ALPHA %d)\n", GL_ONE_MINUS_SRC_ALPHA);
  printf("(defconstant GL_DST_ALPHA %d)\n", GL_DST_ALPHA);
  printf("(defconstant GL_ONE_MINUS_DST_ALPHA %d)\n", GL_ONE_MINUS_DST_ALPHA);
  printf("(defconstant GL_SRC_ALPHA_SATURATE %d)\n", GL_SRC_ALPHA_SATURATE);
  printf("\n");
  
  
  printf(";;; Render Mode\n");
  printf("(defconstant GL_FEEDBACK %d)\n", GL_FEEDBACK);
  printf("(defconstant GL_RENDER %d)\n", GL_RENDER);
  printf("(defconstant GL_SELECT %d)\n", GL_SELECT);
  printf("\n");
  
  
  printf(";;; Feedback\n");
  printf("(defconstant GL_2D %d)\n", GL_2D);
  printf("(defconstant GL_3D %d)\n", GL_3D);
  printf("(defconstant GL_3D_COLOR %d)\n", GL_3D_COLOR);
  printf("(defconstant GL_3D_COLOR_TEXTURE %d)\n", GL_3D_COLOR_TEXTURE);
  printf("(defconstant GL_4D_COLOR_TEXTURE %d)\n", GL_4D_COLOR_TEXTURE);
  printf("(defconstant GL_POINT_TOKEN %d)\n", GL_POINT_TOKEN);
  printf("(defconstant GL_LINE_TOKEN %d)\n", GL_LINE_TOKEN);
  printf("(defconstant GL_LINE_RESET_TOKEN %d)\n", GL_LINE_RESET_TOKEN);
  printf("(defconstant GL_POLYGON_TOKEN %d)\n", GL_POLYGON_TOKEN);
  printf("(defconstant GL_BITMAP_TOKEN %d)\n", GL_BITMAP_TOKEN);
  printf("(defconstant GL_DRAW_PIXEL_TOKEN %d)\n", GL_DRAW_PIXEL_TOKEN);
  printf("(defconstant GL_COPY_PIXEL_TOKEN %d)\n", GL_COPY_PIXEL_TOKEN);
  printf("(defconstant GL_PASS_THROUGH_TOKEN %d)\n", GL_PASS_THROUGH_TOKEN);
  printf("\n");
  
  
  printf(";;; Fog\n");
  printf("(defconstant GL_FOG %d)\n", GL_FOG);
  printf("(defconstant GL_FOG_MODE %d)\n", GL_FOG_MODE);
  printf("(defconstant GL_FOG_DENSITY %d)\n", GL_FOG_DENSITY);
  printf("(defconstant GL_FOG_COLOR %d)\n", GL_FOG_COLOR);
  printf("(defconstant GL_FOG_INDEX %d)\n", GL_FOG_INDEX);
  printf("(defconstant GL_FOG_START %d)\n", GL_FOG_START);
  printf("(defconstant GL_FOG_END %d)\n", GL_FOG_END);
  printf("(defconstant GL_LINEAR %d)\n", GL_LINEAR);
  printf("(defconstant GL_EXP %d)\n", GL_EXP);
  printf("(defconstant GL_EXP2 %d)\n", GL_EXP2);
  printf("\n");
  
  
  printf(";;; Logic Ops\n");
  printf("(defconstant GL_LOGIC_OP %d)\n", GL_LOGIC_OP);
  printf("(defconstant GL_LOGIC_OP_MODE %d)\n", GL_LOGIC_OP_MODE);
  printf("(defconstant GL_CLEAR %d)\n", GL_CLEAR);
  printf("(defconstant GL_SET %d)\n", GL_SET);
  printf("(defconstant GL_COPY %d)\n", GL_COPY);
  printf("(defconstant GL_COPY_INVERTED %d)\n", GL_COPY_INVERTED);
  printf("(defconstant GL_NOOP %d)\n", GL_NOOP);
  printf("(defconstant GL_INVERT %d)\n", GL_INVERT);
  printf("(defconstant GL_AND %d)\n", GL_AND);
  printf("(defconstant GL_NAND %d)\n", GL_NAND);
  printf("(defconstant GL_OR %d)\n", GL_OR);
  printf("(defconstant GL_NOR %d)\n", GL_NOR);
  printf("(defconstant GL_XOR %d)\n", GL_XOR);
  printf("(defconstant GL_EQUIV %d)\n", GL_EQUIV);
  printf("(defconstant GL_AND_REVERSE %d)\n", GL_AND_REVERSE);
  printf("(defconstant GL_AND_INVERTED %d)\n", GL_AND_INVERTED);
  printf("(defconstant GL_OR_REVERSE %d)\n", GL_OR_REVERSE);
  printf("(defconstant GL_OR_INVERTED %d)\n", GL_OR_INVERTED);
  printf("\n");
  
  
  printf(";;; Stencil\n");
  printf("(defconstant GL_STENCIL_TEST %d)\n", GL_STENCIL_TEST);
  printf("(defconstant GL_STENCIL_WRITEMASK %d)\n", GL_STENCIL_WRITEMASK);
  printf("(defconstant GL_STENCIL_BITS %d)\n", GL_STENCIL_BITS);
  printf("(defconstant GL_STENCIL_FUNC %d)\n", GL_STENCIL_FUNC);
  printf("(defconstant GL_STENCIL_VALUE_MASK %d)\n", GL_STENCIL_VALUE_MASK);
  printf("(defconstant GL_STENCIL_REF %d)\n", GL_STENCIL_REF);
  printf("(defconstant GL_STENCIL_FAIL %d)\n", GL_STENCIL_FAIL);
  printf("(defconstant GL_STENCIL_PASS_DEPTH_PASS %d)\n", GL_STENCIL_PASS_DEPTH_PASS);
  printf("(defconstant GL_STENCIL_PASS_DEPTH_FAIL %d)\n", GL_STENCIL_PASS_DEPTH_FAIL);
  printf("(defconstant GL_STENCIL_CLEAR_VALUE %d)\n", GL_STENCIL_CLEAR_VALUE);
  printf("(defconstant GL_STENCIL_INDEX %d)\n", GL_STENCIL_INDEX);
  printf("(defconstant GL_KEEP %d)\n", GL_KEEP);
  printf("(defconstant GL_REPLACE %d)\n", GL_REPLACE);
  printf("(defconstant GL_INCR %d)\n", GL_INCR);
  printf("(defconstant GL_DECR %d)\n", GL_DECR);
  printf("\n");
  
  
  printf(";;; Buffers Pixel Drawing/Reading\n");
  printf("(defconstant GL_NONE %d)\n", GL_NONE);
  printf("(defconstant GL_LEFT %d)\n", GL_LEFT);
  printf("(defconstant GL_RIGHT %d)\n", GL_RIGHT);
  printf("(defconstant GL_FRONT_LEFT %d)\n", GL_FRONT_LEFT);
  printf("(defconstant GL_FRONT_RIGHT %d)\n", GL_FRONT_RIGHT);
  printf("(defconstant GL_BACK_LEFT %d)\n", GL_BACK_LEFT);
  printf("(defconstant GL_BACK_RIGHT %d)\n", GL_BACK_RIGHT);
  printf("(defconstant GL_AUX0 %d)\n", GL_AUX0);
  printf("(defconstant GL_COLOR_INDEX %d)\n", GL_COLOR_INDEX);
  printf("(defconstant GL_STENCIL_BUFFER %d)\n", GL_STENCIL_BUFFER);
  printf("(defconstant GL_DEPTH_BUFFER %d)\n", GL_DEPTH_BUFFER);
  printf("(defconstant GL_RED %d)\n", GL_RED);
  printf("(defconstant GL_GREEN %d)\n", GL_GREEN);
  printf("(defconstant GL_BLUE %d)\n", GL_BLUE);
  printf("(defconstant GL_ALPHA %d)\n", GL_ALPHA);
  printf("(defconstant GL_LUMINANCE %d)\n", GL_LUMINANCE);
  printf("(defconstant GL_LUMINANCE_ALPHA %d)\n", GL_LUMINANCE_ALPHA);
  printf("(defconstant GL_ALPHA_BITS %d)\n", GL_ALPHA_BITS);
  printf("(defconstant GL_RED_BITS %d)\n", GL_RED_BITS);
  printf("(defconstant GL_GREEN_BITS %d)\n", GL_GREEN_BITS);
  printf("(defconstant GL_BLUE_BITS %d)\n", GL_BLUE_BITS);
  printf("(defconstant GL_INDEX_BITS %d)\n", GL_INDEX_BITS);
  printf("(defconstant GL_SUBPIXEL_BITS %d)\n", GL_SUBPIXEL_BITS);
  printf("(defconstant GL_AUX_BUFFERS %d)\n", GL_AUX_BUFFERS);
  printf("(defconstant GL_READ_BUFFER %d)\n", GL_READ_BUFFER);
  printf("(defconstant GL_DRAW_BUFFER %d)\n", GL_DRAW_BUFFER);
  printf("(defconstant GL_DOUBLEBUFFER %d)\n", GL_DOUBLEBUFFER);
  printf("(defconstant GL_STEREO %d)\n", GL_STEREO);
  printf("(defconstant GL_BITMAP %d)\n", GL_BITMAP);
  printf("(defconstant GL_COLOR %d)\n", GL_COLOR);
  printf("(defconstant GL_DEPTH %d)\n", GL_DEPTH);
  printf("(defconstant GL_STENCIL %d)\n", GL_STENCIL);
  printf("(defconstant GL_DITHER %d)\n", GL_DITHER);
  printf("(defconstant GL_RGB %d)\n", GL_RGB);
  printf("(defconstant GL_RGBA %d)\n", GL_RGBA);
  printf("\n");
  
  
  printf(";;; Implementation limits\n");
  printf("(defconstant GL_MAX_MODELVIEW_STACK_DEPTH %d)\n", GL_MAX_MODELVIEW_STACK_DEPTH);
  printf("(defconstant GL_MAX_PROJECTION_STACK_DEPTH %d)\n", GL_MAX_PROJECTION_STACK_DEPTH);
  printf("(defconstant GL_MAX_TEXTURE_STACK_DEPTH %d)\n", GL_MAX_TEXTURE_STACK_DEPTH);
  printf("(defconstant GL_MAX_ATTRIB_STACK_DEPTH %d)\n", GL_MAX_ATTRIB_STACK_DEPTH);
  printf("(defconstant GL_MAX_NAME_STACK_DEPTH %d)\n", GL_MAX_NAME_STACK_DEPTH);
  //printf("(defconstant GL_MAX_DISPLAYLISTS %d)\n", GL_MAX_DISPLAYLISTS);
  printf("(defconstant GL_MAX_LIST_NESTING %d)\n", GL_MAX_LIST_NESTING);
  printf("(defconstant GL_MAX_LIGHTS %d)\n", GL_MAX_LIGHTS);
  printf("(defconstant GL_MAX_CLIP_PLANES %d)\n", GL_MAX_CLIP_PLANES);
  printf("(defconstant GL_MAX_VIEWPORT_DIMS %d)\n", GL_MAX_VIEWPORT_DIMS);
  printf("(defconstant GL_MAX_PIXEL_MAP_TABLE %d)\n", GL_MAX_PIXEL_MAP_TABLE);
  printf("(defconstant GL_MAX_EVAL_ORDER %d)\n", GL_MAX_EVAL_ORDER);
  printf("(defconstant GL_MAX_TEXTURE_SIZE %d)\n", GL_MAX_TEXTURE_SIZE);
  printf("\n");
  
  
  printf(";;; Gets\n");
  printf("(defconstant GL_ATTRIB_STACK_DEPTH %d)\n", GL_ATTRIB_STACK_DEPTH);
  printf("(defconstant GL_COLOR_CLEAR_VALUE %d)\n", GL_COLOR_CLEAR_VALUE);
  printf("(defconstant GL_COLOR_WRITEMASK %d)\n", GL_COLOR_WRITEMASK);
  printf("(defconstant GL_CURRENT_INDEX %d)\n", GL_CURRENT_INDEX);
  printf("(defconstant GL_CURRENT_COLOR %d)\n", GL_CURRENT_COLOR);
  printf("(defconstant GL_CURRENT_NORMAL %d)\n", GL_CURRENT_NORMAL);
  printf("(defconstant GL_CURRENT_RASTER_COLOR %d)\n", GL_CURRENT_RASTER_COLOR);
  printf("(defconstant GL_CURRENT_RASTER_DISTANCE %d)\n", GL_CURRENT_RASTER_DISTANCE);
  printf("(defconstant GL_CURRENT_RASTER_INDEX %d)\n", GL_CURRENT_RASTER_INDEX);
  printf("(defconstant GL_CURRENT_RASTER_POSITION %d)\n", GL_CURRENT_RASTER_POSITION);
  printf("(defconstant GL_CURRENT_RASTER_TEXTURE_COORDS %d)\n", GL_CURRENT_RASTER_TEXTURE_COORDS);
  printf("(defconstant GL_CURRENT_RASTER_POSITION_VALID %d)\n", GL_CURRENT_RASTER_POSITION_VALID);
  printf("(defconstant GL_CURRENT_TEXTURE_COORDS %d)\n", GL_CURRENT_TEXTURE_COORDS);
  printf("(defconstant GL_INDEX_CLEAR_VALUE %d)\n", GL_INDEX_CLEAR_VALUE);
  printf("(defconstant GL_INDEX_MODE %d)\n", GL_INDEX_MODE);
  printf("(defconstant GL_INDEX_WRITEMASK %d)\n", GL_INDEX_WRITEMASK);
  printf("(defconstant GL_MODELVIEW_MATRIX %d)\n", GL_MODELVIEW_MATRIX);
  printf("(defconstant GL_MODELVIEW_STACK_DEPTH %d)\n", GL_MODELVIEW_STACK_DEPTH);
  printf("(defconstant GL_NAME_STACK_DEPTH %d)\n", GL_NAME_STACK_DEPTH);
  printf("(defconstant GL_PROJECTION_MATRIX %d)\n", GL_PROJECTION_MATRIX);
  printf("(defconstant GL_PROJECTION_STACK_DEPTH %d)\n", GL_PROJECTION_STACK_DEPTH);
  printf("(defconstant GL_RENDER_MODE %d)\n", GL_RENDER_MODE);
  printf("(defconstant GL_RGBA_MODE %d)\n", GL_RGBA_MODE);
  printf("(defconstant GL_TEXTURE_MATRIX %d)\n", GL_TEXTURE_MATRIX);
  printf("(defconstant GL_TEXTURE_STACK_DEPTH %d)\n", GL_TEXTURE_STACK_DEPTH);
  printf("(defconstant GL_VIEWPORT %d)\n", GL_VIEWPORT);
  printf("\n");
  
  
  printf("\n");
  
  
  printf(";;; Evaluators\n");
  printf("(defconstant GL_AUTO_NORMAL %d)\n", GL_AUTO_NORMAL);
  printf("(defconstant GL_MAP1_COLOR_4 %d)\n", GL_MAP1_COLOR_4);
  printf("(defconstant GL_MAP1_GRID_DOMAIN %d)\n", GL_MAP1_GRID_DOMAIN);
  printf("(defconstant GL_MAP1_GRID_SEGMENTS %d)\n", GL_MAP1_GRID_SEGMENTS);
  printf("(defconstant GL_MAP1_INDEX %d)\n", GL_MAP1_INDEX);
  printf("(defconstant GL_MAP1_NORMAL %d)\n", GL_MAP1_NORMAL);
  printf("(defconstant GL_MAP1_TEXTURE_COORD_1 %d)\n", GL_MAP1_TEXTURE_COORD_1);
  printf("(defconstant GL_MAP1_TEXTURE_COORD_2 %d)\n", GL_MAP1_TEXTURE_COORD_2);
  printf("(defconstant GL_MAP1_TEXTURE_COORD_3 %d)\n", GL_MAP1_TEXTURE_COORD_3);
  printf("(defconstant GL_MAP1_TEXTURE_COORD_4 %d)\n", GL_MAP1_TEXTURE_COORD_4);
  printf("(defconstant GL_MAP1_VERTEX_3 %d)\n", GL_MAP1_VERTEX_3);
  printf("(defconstant GL_MAP1_VERTEX_4 %d)\n", GL_MAP1_VERTEX_4);
  printf("(defconstant GL_MAP2_COLOR_4 %d)\n", GL_MAP2_COLOR_4);
  printf("(defconstant GL_MAP2_GRID_DOMAIN %d)\n", GL_MAP2_GRID_DOMAIN);
  printf("(defconstant GL_MAP2_GRID_SEGMENTS %d)\n", GL_MAP2_GRID_SEGMENTS);
  printf("(defconstant GL_MAP2_INDEX %d)\n", GL_MAP2_INDEX);
  printf("(defconstant GL_MAP2_NORMAL %d)\n", GL_MAP2_NORMAL);
  printf("(defconstant GL_MAP2_TEXTURE_COORD_1 %d)\n", GL_MAP2_TEXTURE_COORD_1);
  printf("(defconstant GL_MAP2_TEXTURE_COORD_2 %d)\n", GL_MAP2_TEXTURE_COORD_2);
  printf("(defconstant GL_MAP2_TEXTURE_COORD_3 %d)\n", GL_MAP2_TEXTURE_COORD_3);
  printf("(defconstant GL_MAP2_TEXTURE_COORD_4 %d)\n", GL_MAP2_TEXTURE_COORD_4);
  printf("(defconstant GL_MAP2_VERTEX_3 %d)\n", GL_MAP2_VERTEX_3);
  printf("(defconstant GL_MAP2_VERTEX_4 %d)\n", GL_MAP2_VERTEX_4);
  printf("\n");
  
  
  printf(";;; Hints\n");
  printf("(defconstant GL_FOG_HINT %d)\n", GL_FOG_HINT);
  printf("(defconstant GL_LINE_SMOOTH_HINT %d)\n", GL_LINE_SMOOTH_HINT);
  printf("(defconstant GL_PERSPECTIVE_CORRECTION_HINT %d)\n", GL_PERSPECTIVE_CORRECTION_HINT);
  printf("(defconstant GL_POINT_SMOOTH_HINT %d)\n", GL_POINT_SMOOTH_HINT);
  printf("(defconstant GL_POLYGON_SMOOTH_HINT %d)\n", GL_POLYGON_SMOOTH_HINT);
  printf("(defconstant GL_DONT_CARE %d)\n", GL_DONT_CARE);
  printf("(defconstant GL_FASTEST %d)\n", GL_FASTEST);
  printf("(defconstant GL_NICEST %d)\n", GL_NICEST);
  printf("\n");
  
  
  printf(";;; Scissor box\n");
  printf("(defconstant GL_SCISSOR_TEST %d)\n", GL_SCISSOR_TEST);
  printf("(defconstant GL_SCISSOR_BOX %d)\n", GL_SCISSOR_BOX);
  printf("\n");
  
  
  printf(";;; Pixel Mode / Transfer\n");
  printf("(defconstant GL_MAP_COLOR %d)\n", GL_MAP_COLOR);
  printf("(defconstant GL_MAP_STENCIL %d)\n", GL_MAP_STENCIL);
  printf("(defconstant GL_INDEX_SHIFT %d)\n", GL_INDEX_SHIFT);
  printf("(defconstant GL_INDEX_OFFSET %d)\n", GL_INDEX_OFFSET);
  printf("(defconstant GL_RED_SCALE %d)\n", GL_RED_SCALE);
  printf("(defconstant GL_RED_BIAS %d)\n", GL_RED_BIAS);
  printf("(defconstant GL_GREEN_SCALE %d)\n", GL_GREEN_SCALE);
  printf("(defconstant GL_GREEN_BIAS %d)\n", GL_GREEN_BIAS);
  printf("(defconstant GL_BLUE_SCALE %d)\n", GL_BLUE_SCALE);
  printf("(defconstant GL_BLUE_BIAS %d)\n", GL_BLUE_BIAS);
  printf("(defconstant GL_ALPHA_SCALE %d)\n", GL_ALPHA_SCALE);
  printf("(defconstant GL_ALPHA_BIAS %d)\n", GL_ALPHA_BIAS);
  printf("(defconstant GL_DEPTH_SCALE %d)\n", GL_DEPTH_SCALE);
  printf("(defconstant GL_DEPTH_BIAS %d)\n", GL_DEPTH_BIAS);
  printf("(defconstant GL_PIXEL_MAP_S_TO_S_SIZE %d)\n", GL_PIXEL_MAP_S_TO_S_SIZE);
  printf("(defconstant GL_PIXEL_MAP_I_TO_I_SIZE %d)\n", GL_PIXEL_MAP_I_TO_I_SIZE);
  printf("(defconstant GL_PIXEL_MAP_I_TO_R_SIZE %d)\n", GL_PIXEL_MAP_I_TO_R_SIZE);
  printf("(defconstant GL_PIXEL_MAP_I_TO_G_SIZE %d)\n", GL_PIXEL_MAP_I_TO_G_SIZE);
  printf("(defconstant GL_PIXEL_MAP_I_TO_B_SIZE %d)\n", GL_PIXEL_MAP_I_TO_B_SIZE);
  printf("(defconstant GL_PIXEL_MAP_I_TO_A_SIZE %d)\n", GL_PIXEL_MAP_I_TO_A_SIZE);
  printf("(defconstant GL_PIXEL_MAP_R_TO_R_SIZE %d)\n", GL_PIXEL_MAP_R_TO_R_SIZE);
  printf("(defconstant GL_PIXEL_MAP_G_TO_G_SIZE %d)\n", GL_PIXEL_MAP_G_TO_G_SIZE);
  printf("(defconstant GL_PIXEL_MAP_B_TO_B_SIZE %d)\n", GL_PIXEL_MAP_B_TO_B_SIZE);
  printf("(defconstant GL_PIXEL_MAP_A_TO_A_SIZE %d)\n", GL_PIXEL_MAP_A_TO_A_SIZE);
  printf("(defconstant GL_PIXEL_MAP_S_TO_S %d)\n", GL_PIXEL_MAP_S_TO_S);
  printf("(defconstant GL_PIXEL_MAP_I_TO_I %d)\n", GL_PIXEL_MAP_I_TO_I);
  printf("(defconstant GL_PIXEL_MAP_I_TO_R %d)\n", GL_PIXEL_MAP_I_TO_R);
  printf("(defconstant GL_PIXEL_MAP_I_TO_G %d)\n", GL_PIXEL_MAP_I_TO_G);
  printf("(defconstant GL_PIXEL_MAP_I_TO_B %d)\n", GL_PIXEL_MAP_I_TO_B);
  printf("(defconstant GL_PIXEL_MAP_I_TO_A %d)\n", GL_PIXEL_MAP_I_TO_A);
  printf("(defconstant GL_PIXEL_MAP_R_TO_R %d)\n", GL_PIXEL_MAP_R_TO_R);
  printf("(defconstant GL_PIXEL_MAP_G_TO_G %d)\n", GL_PIXEL_MAP_G_TO_G);
  printf("(defconstant GL_PIXEL_MAP_B_TO_B %d)\n", GL_PIXEL_MAP_B_TO_B);
  printf("(defconstant GL_PIXEL_MAP_A_TO_A %d)\n", GL_PIXEL_MAP_A_TO_A);
  printf("(defconstant GL_PACK_ALIGNMENT %d)\n", GL_PACK_ALIGNMENT);
  printf("(defconstant GL_PACK_LSB_FIRST %d)\n", GL_PACK_LSB_FIRST);
  printf("(defconstant GL_PACK_ROW_LENGTH %d)\n", GL_PACK_ROW_LENGTH);
  printf("(defconstant GL_PACK_SKIP_PIXELS %d)\n", GL_PACK_SKIP_PIXELS);
  printf("(defconstant GL_PACK_SKIP_ROWS %d)\n", GL_PACK_SKIP_ROWS);
  printf("(defconstant GL_PACK_SWAP_BYTES %d)\n", GL_PACK_SWAP_BYTES);
  printf("(defconstant GL_UNPACK_ALIGNMENT %d)\n", GL_UNPACK_ALIGNMENT);
  printf("(defconstant GL_UNPACK_LSB_FIRST %d)\n", GL_UNPACK_LSB_FIRST);
  printf("(defconstant GL_UNPACK_ROW_LENGTH %d)\n", GL_UNPACK_ROW_LENGTH);
  printf("(defconstant GL_UNPACK_SKIP_PIXELS %d)\n", GL_UNPACK_SKIP_PIXELS);
  printf("(defconstant GL_UNPACK_SKIP_ROWS %d)\n", GL_UNPACK_SKIP_ROWS);
  printf("(defconstant GL_UNPACK_SWAP_BYTES %d)\n", GL_UNPACK_SWAP_BYTES);
  printf("(defconstant GL_ZOOM_X %d)\n", GL_ZOOM_X);
  printf("(defconstant GL_ZOOM_Y %d)\n", GL_ZOOM_Y);
  printf("\n");
  
  
  printf(";;; Texture mapping\n");
  printf("(defconstant GL_TEXTURE_ENV %d)\n", GL_TEXTURE_ENV);
  printf("(defconstant GL_TEXTURE_ENV_MODE %d)\n", GL_TEXTURE_ENV_MODE);
  printf("(defconstant GL_TEXTURE_1D %d)\n", GL_TEXTURE_1D);
  printf("(defconstant GL_TEXTURE_2D %d)\n", GL_TEXTURE_2D);
  printf("(defconstant GL_TEXTURE_WRAP_S %d)\n", GL_TEXTURE_WRAP_S);
  printf("(defconstant GL_TEXTURE_WRAP_T %d)\n", GL_TEXTURE_WRAP_T);
  printf("(defconstant GL_TEXTURE_MAG_FILTER %d)\n", GL_TEXTURE_MAG_FILTER);
  printf("(defconstant GL_TEXTURE_MIN_FILTER %d)\n", GL_TEXTURE_MIN_FILTER);
  printf("(defconstant GL_TEXTURE_ENV_COLOR %d)\n", GL_TEXTURE_ENV_COLOR);
  printf("(defconstant GL_TEXTURE_GEN_S %d)\n", GL_TEXTURE_GEN_S);
  printf("(defconstant GL_TEXTURE_GEN_T %d)\n", GL_TEXTURE_GEN_T);
  printf("(defconstant GL_TEXTURE_GEN_MODE %d)\n", GL_TEXTURE_GEN_MODE);
  printf("(defconstant GL_TEXTURE_BORDER_COLOR %d)\n", GL_TEXTURE_BORDER_COLOR);
  printf("(defconstant GL_NEAREST_MIPMAP_NEAREST %d)\n", GL_NEAREST_MIPMAP_NEAREST);
  printf("(defconstant GL_NEAREST_MIPMAP_LINEAR %d)\n", GL_NEAREST_MIPMAP_LINEAR);
  printf("(defconstant GL_LINEAR_MIPMAP_NEAREST %d)\n", GL_LINEAR_MIPMAP_NEAREST);
  printf("(defconstant GL_LINEAR_MIPMAP_LINEAR %d)\n", GL_LINEAR_MIPMAP_LINEAR);
  printf("(defconstant GL_OBJECT_LINEAR %d)\n", GL_OBJECT_LINEAR);
  printf("(defconstant GL_OBJECT_PLANE %d)\n", GL_OBJECT_PLANE);
  printf("(defconstant GL_EYE_LINEAR %d)\n", GL_EYE_LINEAR);
  printf("(defconstant GL_EYE_PLANE %d)\n", GL_EYE_PLANE);
  printf("(defconstant GL_SPHERE_MAP %d)\n", GL_SPHERE_MAP);
  printf("(defconstant GL_DECAL %d)\n", GL_DECAL);
  printf("(defconstant GL_MODULATE %d)\n", GL_MODULATE);
  printf("(defconstant GL_NEAREST %d)\n", GL_NEAREST);
  printf("(defconstant GL_REPEAT %d)\n", GL_REPEAT);
  printf("(defconstant GL_CLAMP %d)\n", GL_CLAMP);
  printf("(defconstant GL_S %d)\n", GL_S);
  printf("(defconstant GL_T %d)\n", GL_T);
  printf("(defconstant GL_R %d)\n", GL_R);
  printf("(defconstant GL_Q %d)\n", GL_Q);
  printf("(defconstant GL_TEXTURE_GEN_R %d)\n", GL_TEXTURE_GEN_R);
  printf("(defconstant GL_TEXTURE_GEN_Q %d)\n", GL_TEXTURE_GEN_Q);
  printf("\n");
  
  
  printf(";;; Utility\n");
  printf("(defconstant GL_VENDOR %d)\n", GL_VENDOR);
  printf("(defconstant GL_RENDERER %d)\n", GL_RENDERER);
  printf("(defconstant GL_VERSION %d)\n", GL_VERSION);
  printf("(defconstant GL_EXTENSIONS %d)\n", GL_EXTENSIONS);
  printf("\n");
  
  
  printf(";;; Errors\n");
  printf("(defconstant GL_INVALID_VALUE %d)\n", GL_INVALID_VALUE);
  printf("(defconstant GL_INVALID_ENUM %d)\n", GL_INVALID_ENUM);
  printf("(defconstant GL_INVALID_OPERATION %d)\n", GL_INVALID_OPERATION);
  printf("(defconstant GL_STACK_OVERFLOW %d)\n", GL_STACK_OVERFLOW);
  printf("(defconstant GL_STACK_UNDERFLOW %d)\n", GL_STACK_UNDERFLOW);
  printf("(defconstant GL_OUT_OF_MEMORY %d)\n", GL_OUT_OF_MEMORY);
  printf("\n");
  
  
  printf(";;; Extensions\n");
  printf("(defconstant GL_CONSTANT_COLOR_EXT %d)\n", GL_CONSTANT_COLOR_EXT);
  printf("(defconstant GL_ONE_MINUS_CONSTANT_COLOR_EXT %d)\n", GL_ONE_MINUS_CONSTANT_COLOR_EXT);
  printf("(defconstant GL_CONSTANT_ALPHA_EXT %d)\n", GL_CONSTANT_ALPHA_EXT);
  printf("(defconstant GL_ONE_MINUS_CONSTANT_ALPHA_EXT %d)\n", GL_ONE_MINUS_CONSTANT_ALPHA_EXT);
  printf("(defconstant GL_BLEND_EQUATION_EXT %d)\n", GL_BLEND_EQUATION_EXT);
  printf("(defconstant GL_MIN_EXT %d)\n", GL_MIN_EXT);
  printf("(defconstant GL_MAX_EXT %d)\n", GL_MAX_EXT);
  printf("(defconstant GL_FUNC_ADD_EXT %d)\n", GL_FUNC_ADD_EXT);
  printf("(defconstant GL_FUNC_SUBTRACT_EXT %d)\n", GL_FUNC_SUBTRACT_EXT);
  printf("(defconstant GL_FUNC_REVERSE_SUBTRACT_EXT %d)\n", GL_FUNC_REVERSE_SUBTRACT_EXT);
  printf("(defconstant GL_BLEND_COLOR_EXT %d)\n", GL_BLEND_COLOR_EXT);
  printf("(defconstant GL_REPLACE_EXT %d)\n", GL_REPLACE_EXT);
  printf("\n");
  
  
  printf("\n");
  
  
  printf(";;; GL_NO_ERROR must be zero)\n");
  printf("(defconstant GL_NO_ERROR %d)\n", GL_NO_ERROR);
  printf("\n");
  
  
  printf("\n");
  
  
  printf("\n");
  
  
  printf(";;; Compile_time tests for extensions:\n");
  printf("(defconstant GL_EXT_blend_color %d)\n", GL_EXT_blend_color);
  printf("(defconstant GL_EXT_blend_logic_op %d)\n", GL_EXT_blend_logic_op);
  printf("(defconstant GL_EXT_blend_minmax %d)\n", GL_EXT_blend_minmax);
  printf("(defconstant GL_EXT_blend_subtract %d)\n", GL_EXT_blend_subtract);
  printf("\n");
  
  
  printf("\n");
  
  
  printf("(defconstant GL_ACCUM_BUFFER_BIT %d)\n", GL_ACCUM_BUFFER_BIT);
  printf("(defconstant GL_COLOR_BUFFER_BIT %d)\n", GL_COLOR_BUFFER_BIT);
  printf("(defconstant GL_CURRENT_BIT %d)\n", GL_CURRENT_BIT);
  printf("(defconstant GL_DEPTH_BUFFER_BIT %d)\n", GL_DEPTH_BUFFER_BIT);
  printf("(defconstant GL_ENABLE_BIT %d)\n", GL_ENABLE_BIT);
  printf("(defconstant GL_EVAL_BIT %d)\n", GL_EVAL_BIT);
  printf("(defconstant GL_FOG_BIT %d)\n", GL_FOG_BIT);
  printf("(defconstant GL_HINT_BIT %d)\n", GL_HINT_BIT);
  printf("(defconstant GL_LIGHTING_BIT %d)\n", GL_LIGHTING_BIT);
  printf("(defconstant GL_LINE_BIT %d)\n", GL_LINE_BIT);
  printf("(defconstant GL_LIST_BIT %d)\n", GL_LIST_BIT);
  printf("(defconstant GL_PIXEL_MODE_BIT %d)\n", GL_PIXEL_MODE_BIT);
  printf("(defconstant GL_POINT_BIT %d)\n", GL_POINT_BIT);
  printf("(defconstant GL_POLYGON_BIT %d)\n", GL_POLYGON_BIT);
  printf("(defconstant GL_POLYGON_STIPPLE_BIT %d)\n", GL_POLYGON_STIPPLE_BIT);
  printf("(defconstant GL_SCISSOR_BIT %d)\n", GL_SCISSOR_BIT);
  printf("(defconstant GL_STENCIL_BUFFER_BIT %d)\n", GL_STENCIL_BUFFER_BIT);
  printf("(defconstant GL_TEXTURE_BIT %d)\n", GL_TEXTURE_BIT);
  printf("(defconstant GL_TRANSFORM_BIT %d)\n", GL_TRANSFORM_BIT);
  printf("(defconstant GL_VIEWPORT_BIT %d)\n", GL_VIEWPORT_BIT);
  printf("(defconstant GL_ALL_ATTRIB_BITS %d)\n", GL_ALL_ATTRIB_BITS);
  printf("\n");
}
