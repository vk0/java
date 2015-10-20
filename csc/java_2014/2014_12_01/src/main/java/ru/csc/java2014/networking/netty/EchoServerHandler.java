package ru.csc.java2014.networking.netty;

import io.netty.buffer.ByteBuf;
import io.netty.channel.ChannelHandlerContext;
import io.netty.channel.SimpleChannelInboundHandler;

import java.util.logging.Level;
import java.util.logging.Logger;


public class EchoServerHandler extends SimpleChannelInboundHandler<ByteBuf> {

    private static final Logger LOG = Logger.getLogger(EchoServerHandler.class.getName());

    @Override
    public void exceptionCaught(ChannelHandlerContext ctx, Throwable cause) throws Exception {
        LOG.log(Level.SEVERE, null, cause);
        ctx.close();
    }

    @Override
    protected void channelRead0(ChannelHandlerContext ctx, ByteBuf byteBuf) throws Exception {
        LOG.info("Got message from " + ctx.channel().remoteAddress());
        ctx.writeAndFlush(byteBuf.copy());
    }
}
