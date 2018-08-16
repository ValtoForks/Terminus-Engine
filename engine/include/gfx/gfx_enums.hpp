#pragma once

#include <core/terminus_macros.hpp>

TE_BEGIN_TERMINUS_NAMESPACE

enum CommandPoolType
{
	GFX_CMD_POOL_GRAPHICS = 0,
	GFX_CMD_POOL_COMPUTE = 1
};

enum PipelineType
{
	GFX_PIPELINE_GRAPHICS = 0,
	GFX_PIPELINE_COMPUTE  = 1
};

enum LoadOp
{
	GFX_LOAD_OP_DONT_CARE = 0,
	GFX_LOAD_OP_LOAD = 1,
	GFX_LOAD_OP_CLEAR = 2
};

enum ResourceState
{
	GFX_RESOURCE_STATE_UNDEFINED = 0,
	GFX_RESOURCE_STATE_VERTEX_AND_CONSTANT_BUFFER = 0x1,
	GFX_RESOURCE_STATE_INDEX_BUFFER = 0x2,
	GFX_RESOURCE_STATE_RENDER_TARGET = 0x4,
	GFX_RESOURCE_STATE_UNORDERED_ACCESS = 0x8,
	GFX_RESOURCE_STATE_DEPTH_WRITE = 0x10,
	GFX_RESOURCE_STATE_DEPTH_READ = 0x20,
	GFX_RESOURCE_STATE_NON_PIXEL_SHADER_RESOURCE = 0x40,
	GFX_RESOURCE_STATE_SHADER_RESOURCE = 0x40 | 0x80,
	GFX_RESOURCE_STATE_STREAM_OUT = 0x100,
	GFX_RESOURCE_STATE_INDIRECT_ARGUMENT = 0x200,
	GFX_RESOURCE_STATE_COPY_DEST = 0x400,
	GFX_RESOURCE_STATE_COPY_SOURCE = 0x800,
	GFX_RESOURCE_STATE_GENERIC_READ = (((((0x1 | 0x2) | 0x40) | 0x80) | 0x200) | 0x800),
	GFX_RESOURCE_STATE_PRESENT = 0x4000,
	GFX_RESOURCE_STATE_COMMON = 0x8000
};

enum BufferType
{
	GFX_BUFFER_VERTEX = 0,
	GFX_BUFFER_INDEX = 1,
	GFX_BUFFER_UNIFORM = 2,
	GFX_BUFFER_STORAGE = 3,
	GFX_BUFFER_INDIRECT_ARGUMENT = 4
};

enum DataType
{
	GFX_DATA_TYPE_BYTE = 0,
	GFX_DATA_TYPE_UBYTE = 1,
	GFX_DATA_TYPE_INT16 = 2,
	GFX_DATA_TYPE_INT32 = 3,
	GFX_DATA_TYPE_UINT16 = 4,
	GFX_DATA_TYPE_UINT32 = 5,
	GFX_DATA_TYPE_FLOAT = 6
};

enum ShaderStage
{
	GFX_SHADER_STAGE_VERTEX = 0,
	GFX_SHADER_STAGE_FRAGMENT = 1,
	GFX_SHADER_STAGE_GEOMETRY = 2,
	GFX_SHADER_STAGE_TESS_CONTROL = 3,
	GFX_SHADER_STAGE_TESS_EVAL = 4,
	GFX_SHADER_STAGE_COMPUTE = 5
};

enum ShaderStageBit
{
	GFX_SHADER_STAGE_VERTEX_BIT = 1,
	GFX_SHADER_STAGE_FRAGMENT_BIT = 2,
	GFX_SHADER_STAGE_GEOMETRY_BIT = 4,
	GFX_SHADER_STAGE_TESS_CONTROL_BIT = 8,
	GFX_SHADER_STAGE_TESS_EVAL_BIT = 16,
	GFX_SHADER_STAGE_ALL_BIT = 31,
	GFX_SHADER_STAGE_COMPUTE_BIT = 32
};

enum PrimitiveTopology
{
	GFX_PRIMITIVE_TOPOLOGY_POINTS = 0,
	GFX_PRIMITIVE_TOPOLOGY_TRIANGLES = 1,
	GFX_PRIMITIVE_TOPOLOGY_TRIANGLE_STRIP = 2,
	GFX_PRIMITIVE_TOPOLOGY_LINES = 3,
	GFX_PRIMITIVE_TOPOLOGY_LINE_STRIP = 4,
	GFX_PRIMITIVE_TOPOLOGY_PATCHES = 5
};

enum BufferMapUsage
{
	GFX_BUFFER_MAP_READ = 1,
	GFX_BUFFER_MAP_WRITE = 2,
	GFX_BUFFER_MAP_READ_WRITE = 4,
	GFX_BUFFER_MAP_PERSISTANT = 8
};

enum TextureUsage
{
	GFX_TEXTURE_USAGE_NONE = 1,
	GFX_TEXTURE_USAGE_READABLE = 2,
	GFX_TEXTURE_USAGE_WRITABLE = 4,
	GFX_TEXTURE_USAGE_DRAWABLE = 8
};

enum BufferUsage
{
	GFX_BUFFER_USAGE_READABLE = 1,
	GFX_BUFFER_USAGE_WRITABLE = 2
};

enum CullMode
{
	GFX_CULL_MODE_FRONT = 0,
	GFX_CULL_MODE_BACK = 1,
	GFX_CULL_MODE_FRONT_AND_BACK = 2,
	GFX_CULL_MODE_NONE = 3
};

enum FillMode
{
	GFX_FILL_MODE_SOLID = 0,
	GFX_FILL_MODE_WIREFRAME = 1
};

enum StencilOp
{
	GFX_STENCIL_OP_KEEP = 0,
	GFX_STENCIL_OP_ZERO = 1,
	GFX_STENCIL_OP_REPLACE = 2,
	GFX_STENCIL_OP_INCR_SAT = 3,
	GFX_STENCIL_OP_DECR_SAT = 4,
	GFX_STENCIL_OP_INVERT = 5,
	GFX_STENCIL_OP_INCR = 6,
	GFX_STENCIL_OP_DECR = 7
};

enum CompFunc
{
	GFX_COMP_FUNC_NEVER = 0,
	GFX_COMP_FUNC_LESS = 1,
	GFX_COMP_FUNC_EQUAL = 2,
	GFX_COMP_FUNC_LESS_EQUAL = 3,
	GFX_COMP_FUNC_GREATER = 4,
	GFX_COMP_FUNC_NOT_EQUAL = 5,
	GFX_COMP_FUNC_GREATER_EQUAL = 6,
	GFX_COMP_FUNC_ALWAYS = 7
};

enum ClearTarget
{
	GFX_CLEAR_TARGET_COLOR = 1,
	GFX_CLEAR_TARGET_DEPTH = 2,
	GFX_CLEAR_TARGET_STENCIL = 4,
	GFX_CLEAR_TARGET_ALL = GFX_CLEAR_TARGET_COLOR | GFX_CLEAR_TARGET_DEPTH | GFX_CLEAR_TARGET_STENCIL
};

enum TextureType
{
	GFX_TEXTURE_1D = 0,
	GFX_TEXTURE_2D = 1,
	GFX_TEXTURE_3D = 2,
	GFX_TEXTURE_CUBE = 3,
	GFX_TEXTURE_CUBE_POSITIVE_X = GFX_TEXTURE_CUBE + 1,
	GFX_TEXTURE_CUBE_NEGATIVE_X = GFX_TEXTURE_CUBE + 2,
	GFX_TEXTURE_CUBE_POSITIVE_Y = GFX_TEXTURE_CUBE + 3,
	GFX_TEXTURE_CUBE_NEGATIVE_Y = GFX_TEXTURE_CUBE + 4,
	GFX_TEXTURE_CUBE_POSITIVE_Z = GFX_TEXTURE_CUBE + 5,
	GFX_TEXTURE_CUBE_NEGATIVE_Z = GFX_TEXTURE_CUBE + 6
};

enum CubeFaces
{
	GFX_CUBE_FACE_POSITIVE_X = 0,
	GFX_CUBE_FACE_NEGATIVE_X = 1,
	GFX_CUBE_FACE_POSITIVE_Y = 2,
	GFX_CUBE_FACE_NEGATIVE_Y = 3,
	GFX_CUBE_FACE_POSITIVE_Z = 4,
	GFX_CUBE_FACE_NEGATIVE_Z = 5
};

enum TextureAddressMode
{
	GFX_ADDRESS_REPEAT = 0,
	GFX_ADDRESS_MIRRORED_REPEAT = 1,
	GFX_ADDRESS_CLAMP_TO_EDGE = 2,
	GFX_ADDRESS_CLAMP_TO_BORDER = 3
};

enum TextureFormat
{
	// @TODO: Add compressed formats
	GFX_FORMAT_UNKNOWN = -1,
	GFX_FORMAT_R32G32B32_FLOAT = 0,
	GFX_FORMAT_R32G32B32A32_FLOAT = 1,
	GFX_FORMAT_R32G32B32_UINT = 2,
	GFX_FORMAT_R32G32B32A32_UINT = 3,
	GFX_FORMAT_R32G32B32_INT = 4,
	GFX_FORMAT_R32G32B32A32_INT = 5,
	GFX_FORMAT_R16G16_FLOAT = 6,
	GFX_FORMAT_R16G16B16_FLOAT = 7,
	GFX_FORMAT_R16G16B16A16_FLOAT = 8,
	GFX_FORMAT_R16G16B16_UINT = 9,
	GFX_FORMAT_R16G16B16A16_UINT = 10,
	GFX_FORMAT_R16G16B16_INT = 11,
	GFX_FORMAT_R16G16B16A16_INT = 12,
	GFX_FORMAT_R8G8B8_UNORM = 13,
	GFX_FORMAT_R8G8B8A8_UNORM = 14,
	GFX_FORMAT_R8G8B8_UNORM_SRGB = 15,
	GFX_FORMAT_R8G8B8A8_UNORM_SRGB = 16,
	GFX_FORMAT_R8G8B8_SNORM = 17,
	GFX_FORMAT_R8G8B8A8_SNORM = 18,
	GFX_FORMAT_R8G8B8_INT = 19,
	GFX_FORMAT_R8G8B8A8_INT = 20,
	GFX_FORMAT_R8G8B8_UINT = 21,
	GFX_FORMAT_R8G8B8A8_UINT = 22,
	GFX_FORMAT_R8_UNORM = 23,
	GFX_FORMAT_R8_SNORM = 24,
	GFX_FORMAT_D32_FLOAT_S8_UINT = 25,
	GFX_FORMAT_D24_FLOAT_S8_UINT = 26,
	GFX_FORMAT_D16_FLOAT = 27,
	GFX_FORMAT_R32G32_FLOAT = 28,
	GFX_FORMAT_R16_FLOAT = 29,
	GFX_FORMAT_B8G8R8A8_UNORM = 30,
	GFX_FORMAT_B8G8R8A8_SNORM = 31
};

enum SampleCount
{
	GFX_SAMPLE_COUNT_1,
	GFX_SAMPLE_COUNT_2,
	GFX_SAMPLE_COUNT_4,
	GFX_SAMPLE_COUNT_8,
	GFX_SAMPLE_COUNT_16,
	GFX_SAMPLE_COUNT_32,
	GFX_SAMPLE_COUNT_64
};

enum TextureFilter
{
	GFX_FILTER_LINEAR = 0,
	GFX_FILTER_NEAREST = 1,
	GFX_FILTER_LINEAR_ALL = 2,
	GFX_FILTER_NEAREST_ALL = 3,
	GFX_FILTER_ANISOTROPIC_ALL = 4,
	GFX_FILTER_LINEAR_MIPMAP_NEAREST = 5,
	GFX_FILTER_NEAREST_MIPMAP_LINEAR = 6,
};

enum BlendOp
{
	GFX_BLEND_OP_ADD = 0,
	GFX_BLEND_OP_SUBTRACT = 1,
	GFX_BLEND_OP_REVERSE_SUBTRACT = 2,
	GFX_BLEND_OP_MIN = 3,
	GFX_BLEND_OP_MAX = 4
};

enum BlendFunc
{
	GFX_BLEND_FUNC_ZERO = 0,
	GFX_BLEND_FUNC_ONE = 1,
	GFX_BLEND_FUNC_SRC_COLOR = 2,
	GFX_BLEND_FUNC_ONE_MINUS_SRC_COLOR = 3,
	GFX_BLEND_FUNC_DST_COLOR = 4,
	GFX_BLEND_FUNC_ONE_MINUS_DST_COLOR = 5,
	GFX_BLEND_FUNC_SRC_ALPHA = 6,
	GFX_BLEND_FUNC_ONE_MINUS_SRC_ALPHA = 7,
	GFX_BLEND_FUNC_DST_ALPHA = 8,
	GFX_BLEND_FUNC_ONE_MINUS_DST_ALPHA = 9,
	GFX_BLEND_FUNC_CONSTANT_COLOR = 10,
	GFX_BLEND_FUNC_ONE_MINUS_CONSTANT_COLOR = 11,
	GFX_BLEND_FUNC_CONSTANT_ALPHA = 12,
	GFX_BLEND_FUNC_ONE_MINUS_CONSTANT_ALPHA = 13,
	GFX_BLEND_FUNC_SRC_ALPHA_SATURATE = 14,
	GFX_BLEND_FUNC_SRC1_COLOR = 15,
	GFX_BLEND_FUNC_ONE_MINUS_SRC1_COLOR = 16,
	GFX_BLEND_FUNC_SRC1_ALPHA = 17,
	GFX_BLEND_FUNC_ONE_MINUS_SRC1_ALPHA = 18
};

enum LogicOp
{
	GFX_LOGIC_OP_CLEAR = 0,
	GFX_LOGIC_OP_AND = 1,
	GFX_LOGIC_OP_AND_REVERSE = 2,
	GFX_LOGIC_OP_COPY = 3,
	GFX_LOGIC_OP_AND_INVERTED = 4,
	GFX_LOGIC_OP_NO_OP = 5,
	GFX_LOGIC_OP_XOR = 6,
	GFX_LOGIC_OP_OR = 7,
	GFX_LOGIC_OP_NOR = 8,
	GFX_LOGIC_OP_EQUIVALENT = 9,
	GFX_LOGIC_OP_INVERT = 10,
	GFX_LOGIC_OP_OR_REVERSE = 11,
	GFX_LOGIC_OP_COPY_INVERTED = 12,
	GFX_LOGIC_OP_OR_INVERTED = 13,
	GFX_LOGIC_OP_NAND = 14,
	GFX_LOGIC_OP_SET = 15
};

enum DescriptorType
{
	GFX_DESCRIPTOR_SAMPLER = 0,
	GFX_DESCRIPTOR_TEXTURE = 1,
	GFX_DESCRIPTOR_UNIFORM_BUFFER = 2,
	GFX_DESCRIPTOR_STORAGE_BUFFER = 3,
	GFX_DESCRIPTOR_UNIFORM_BUFFER_DYNAMIC = 4,
	GFX_DESCRIPTOR_STORAGE_BUFFER_DYNAMIC = 5
};

TE_END_TERMINUS_NAMESPACE